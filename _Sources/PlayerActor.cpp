#include "precomp.h"

#include "PlayerActor.h"

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
				
				//ground_check_collider_->offset = *new vec2(0, 0.25f);
			}

			void PlayerActor::Update()
			{
				//TODO: Check Player State / fire mario for run speed (as bit flags)

				//Special

				internal_velocity_.y += 100 * DeltaTime();
				
				Jump();
				
				Walk();

				//ground_check_collider_->DebugBounds(IsGrounded() ? 0x00FFFF : 0xFF0000);

				transform_->Translate(internal_velocity_ * DeltaTime());
			}

			bool PlayerActor::IsGrounded() const
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
						return true;
					}
				}

				return false;
			}

			void PlayerActor::Walk()
			{
				const float acceleration = IsGrounded()
									? Input()->GetKeyDown("Special") ? ground_run_acceleration_ : ground_walk_acceleration_ //Different speed based on whether we're sprinting or not.
									: air_acceleration_; //Different speed if we're not grounded.

				const float input_dir = (Input()->GetKeyDown("Right") - Input()->GetKeyDown("Left")); //left = -1, right = +1, left+right = 0, none = 0

				//TODO: Maybe also check wall collisions in here?

				if(!IsZero(input_dir)) //If there is Input, accelerate, else decelerate.
				{
					internal_velocity_.x = MoveTowards(internal_velocity_.x, max_speed_ * input_dir, acceleration * DeltaTime());
				}
				else
				{
					//TODO: See if you have to decelerate in air as well.
					
					internal_velocity_.x = MoveTowards(internal_velocity_.x, 0, ground_deceleration_ * DeltaTime());
				}
			}

			void PlayerActor::Jump()
			{
				if(!IsGrounded()) return;
				
				internal_velocity_.y = 0;

				if(Input()->GetKeyDown("Up"))
				{
					internal_velocity_.y = -sqrt(2 * jump_height_ * abs(gravity_));
				}

				/*
				if (Input()->jump.is_pressed)
				{
					//_jump_charge_timer += delta_time;
					//charging_ = true;

				}
				*/
				//else if(charging_)
				//{
					//charging_ = false;

					//Animate
					//Play Sound

					//Add Jump Force
				//}

			}

			void PlayerActor::ResolveIntersects()
			{
				//(Angle(colliderDistance.normal, *new vec2(0, -1));

				
				//Detect colliders in players Collider

				//foreach(intersecting_collider in intersections)
				{
					//if(intersecting_collider == this->collider_) continue; //Skip self

					//ColliderDistance colliderDistance = intersecting_collider.Distance(this->collider_);

					/*
					if (colliderDistance.isOverlapped)
					{
						Translate(colliderDistance.resolve_direction);
					}
					*/
				}
			}
		}
	}
}
