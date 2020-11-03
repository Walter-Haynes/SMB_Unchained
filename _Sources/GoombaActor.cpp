#include "precomp.h"

#include "GoombaActor.h"

#include "PlayerActor.h"

#include "SuperMarioBros.h"

namespace Game
{
	namespace Prefabs
	{
		namespace Actors
		{
			GoombaActor::GoombaActor() : Actor(new Sprite(new Surface("assets/Actors/GoombaActor.png"), 1))
			{
				AddComponent(player_check_trigger_ = new ColliderComponent());
				player_check_trigger_->bounds = *new vec2(1, 0.5f);
				player_check_trigger_->offset = *new vec2(0, -0.5f);
				player_check_trigger_->is_trigger = true;
			}

			GoombaActor::~GoombaActor()
			{
				RemoveComponent(player_check_trigger_);
			}

			void GoombaActor::Update()
			{
				if(!CheckIsGrounded())
				{
					ApplyGravity();
				}
				
				CheckWallCollisions();
				
				Walk();

				//CheckWallCollisions();
				
				transform_->Update();

				player_check_trigger_->DebugBounds(0x00FF00);

				ResolveIntersects();

				KillIfStomped();
			}

			void GoombaActor::Kill()
			{
				SuperMarioBros::Instance()->DeleteGoombas();
				delete(this);
			}

			bool GoombaActor::CheckIsGrounded() const
			{
				//Doesn't particularly scale well, but people keep telling me to KISS, so I WILL.
				for (int i = 0; i < ColliderComponent::GetCount(); ++i)
				{
					ColliderComponent* check_against = ColliderComponent::GetInstance(i);

					//TODO: Check based on tags / collision matrix.

					//Skip own colliders.
					if (check_against == this->collider_) continue;
					//if (check_against == this->ground_check_collider_) continue;

					if (check_against->is_trigger) continue;

					//return true if the collider we're checking against collides with the player's "ground check collider".
					if (collider_->CollidesWith(check_against))
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

			void GoombaActor::KillIfStomped()
			{
				if(PlayerActor::Instance()->GetCollider()->CollidesWith(player_check_trigger_))
				{
					this->Kill();
				}
			}

			void GoombaActor::CheckWallCollisions()
			{

				for (int i = 0; i < ColliderComponent::GetCount(); ++i)
				{
					ColliderComponent* check_against = ColliderComponent::GetInstance(i);

					//Skip own colliders.
					if (check_against == this->collider_) continue;

					//Skip triggers.
					if (check_against->is_trigger) continue;

					if (collider_->CollidesWith(check_against))
					{
						ColliderComponent::Hit2D* hit = collider_->Intersects(check_against);

						//Only change direction if we've hit a wall, otherwise keep going.
						if (hit)
						{
							//Left
							if(Equals(hit->normal.x, -1) && hit->delta.x < -1.05f)
							{
								//std::cout << "L" << std::endl;
								input_dir_ = 1; //flip to going right.
							}
							//Right
							if(Equals(hit->normal.x,  1) && hit->delta.x >  1.05f)
							{
								//std::cout << "R" << std::endl;
								input_dir_ =  -1; //flip to going left
							}
						}
					}
				}
				
			}

			void GoombaActor::Walk()
			{
				transform_->velocity.x = input_dir_ * max_speed_;
			}
		}
	}
}
