#include "precomp.h"

#include "PlayerActor.h"


#include <iostream>
#include <MathUtilities.h>
using namespace Engine::MathUtilities;

namespace Game
{
	namespace Prefabs
	{
		namespace Actors
		{
			PlayerActor::PlayerActor() : Actor(new Sprite(new Surface("assets/Actors/PlayerActor.png"), 1))
			{
				AddComponent(ground_check_collider_ = new ColliderComponent());
				ground_check_collider_->bounds = *new vec2(1.0f, 1.0f);
				//ground_check_collider_->offset = *new vec2(0, 0.25f); //a way to check for ground even when Mario is a little bit above the ground.
			}

			void PlayerActor::Update()
			{
				//TODO: Check Player State / if he's fire mario for run speed (as bit flags)

				//Special

				ApplyGravity();
				
				Jump();
				
				Walk();

				transform_->Update();

				ResolveIntersects();

				is_grounded_ = CheckIsGrounded();
			}

			float PlayerActor::Gravity() const
			{
				return gravity_;
			}

			bool PlayerActor::CheckIsGrounded() const
			{
				//Doesn't particularly scale well, but people keep telling me to KISS, so I WILL.
				for (int i = 0; i < ColliderComponent::GetCount(); ++i)
				{
					ColliderComponent* check_against = ColliderComponent::GetInstance(i);

					//TODO: Check based on tags / collision matrix.
					
					//Skip own colliders.
					if (check_against == this->collider_) continue;
					if (check_against == this->ground_check_collider_) continue;

					//return true if the collider we're checking against collides with the player's "ground check collider".
					if(ground_check_collider_->CollidesWith(check_against)) 
					{
						ColliderComponent::Hit2D* hit = collider_->Intersects(check_against);

						//Only grounded if the normal points upwards.
						if (Equals(hit->normal.y, 1))
						{
							return true;
						}
					}
				}

				return false;
			}

			PlayerActor::Collisions* PlayerActor::CheckCollision()
			{
				const auto collisions = new Collisions();
				
				//Doesn't particularly scale well, but people keep telling me to KISS, so I WILL.
				for (int i = 0; i < ColliderComponent::GetCount(); ++i)
				{
					ColliderComponent* check_against = ColliderComponent::GetInstance(i);

					//TODO: Check based on tags / collision matrix.

					//Skip own colliders.
					if (check_against == this->collider_) continue;
					
					if (check_against == this->ground_check_collider_) continue;

					//return true if the collider we're checking against collides with the player's "ground check collider".
					if (collider_->CollidesWith(check_against))
					{
						//TODO: Get collision point from colliders.

						
						//return true;
					}
				}

				return collisions;
			}

			void PlayerActor::Walk()
			{
				//TODO: Player states, Ground_Walk, Ground_Idle, Jump etc (use for animation) bitflags for Left/Right also please thank you.
				
				const float acceleration = is_grounded_
									? Input()->GetKey("Special") ? ground_run_acceleration_ : ground_walk_acceleration_ //Different speed based on whether we're sprinting or not.
									: air_acceleration_; //Different speed if we're not grounded.

				const float input_dir = (Input()->GetKey("Right") - Input()->GetKey("Left")); //left = -1, right = +1, left+right = 0, none = 0

				//TODO: Maybe also check wall collisions in here?

				if(!IsZero(input_dir)) //If there is Input, accelerate, else decelerate.
				{
					transform_->velocity.x = MoveTowards(transform_->velocity.x, max_speed_ * input_dir, acceleration * DeltaTime());
				}
				else
				{
					//TODO: See if you have to decelerate in air as well.
					
					transform_->velocity.x = MoveTowards(transform_->velocity.x, 0, ground_deceleration_ * DeltaTime());
				}
			}

			void PlayerActor::Jump()
			{
				if(!is_grounded_) return;
				
				transform_->velocity.y = 0;

				if(Input()->GetKeyDown("Up"))
				{
					transform_->velocity.y = -sqrt(2 * jump_height_ * abs(Gravity()));
				}
			}

			void PlayerActor::ResolveIntersects()
			{
				for (int i = 0; i < ColliderComponent::GetCount(); ++i)
				{
					ColliderComponent* check_against = ColliderComponent::GetInstance(i);

					//TODO: Check based on tags / collision matrix.

					//Skip own colliders.
					if (check_against == this->collider_) continue;

					if (check_against == this->ground_check_collider_) continue;

					//return true if the collider we're checking against collides with the player's "ground check collider".
					if (collider_->CollidesWith(check_against))
					{
						//TODO: Get collision point from colliders.

						ColliderComponent::Hit2D* hit = collider_->Intersects(check_against);

						if(hit)
						{
							if(Equals(hit->normal.y, 1)) //Down
							{	
								transform_->velocity.y = 0;
							}
							if(Equals(hit->normal.y, -1)) //Up
							{
								transform_->velocity.y = 0;

								transform_->position.y -= hit->delta.y + 1;
							}

							//Bug: We check the delta with horizontal checks for now (hit->delta.length() > 1.1f)
							//	 This is a hack, I'm doing it for now as I'm having issues with left/right collision when walking over gaps in tiles.
							
							
							if(Equals(hit->normal.x, -1) && hit->delta.x < -1.1f) //Left
							{	
								//Stop movement in that direction.
								transform_->velocity.x = 0;

								//Translate out of the intersect.
								transform_->position.x -= (hit->delta.x + 1);
							}
							if(Equals(hit->normal.x, 1) && hit->delta.x > 1.1f) //Right
							{
								//Stop movement in that direction.
								transform_->velocity.x = 0;
								
								//Translate out of the intersect.
								transform_->position.x -= (hit->delta.x - 1);
							}

							//Debug Collisions
							check_against->DebugBounds(0xF00FFFF);

							const vec2 end_screen_pos = Engine::Managers::RenderManager::Instance()->ConvertWorldToScreen(hit->contact - hit->delta) * UNITS_TO_PIXELS;

							Engine::Managers::RenderManager::Instance()->GetMainCamera()->GetWindow()->Box(
								static_cast<int>(end_screen_pos.x) - 2,
								static_cast<int>(end_screen_pos.y) + 2,
								static_cast<int>(end_screen_pos.x) + 2,
								static_cast<int>(end_screen_pos.y) - 2, 0x00FFFFF);

							//TODO: Only Save Grounding after resolving collisions.
						}
					}
				}
			}

		}
	}
}
