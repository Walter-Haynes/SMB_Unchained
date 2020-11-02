#include "precomp.h"

#include "GoombaActor.h"

namespace Game
{
	namespace Prefabs
	{
		namespace Actors
		{
			GoombaActor::GoombaActor() : Actor(new Sprite(new Surface("assets/Actors/GoombaActor.png"), 1))
			{
				//AddComponent(ground_check_collider_ = new ColliderComponent());
				//ground_check_collider_->bounds = *new vec2(1.0f, 1.0f);
				//ground_check_collider_->offset = *new vec2(0, 0.25f);
			}

			void GoombaActor::Update()
			{
				ApplyGravity();
				
				CheckWallCollisions();
				
				Walk();

				transform_->Update();

				ResolveIntersects();

			}

			void GoombaActor::CheckWallCollisions()
			{
				//input_dir_ = 0;
				//if Collision on the left
					//input_dir_ =  1;  //right
				//else if Collision on the right.
					//input_dir_ = -1; //left

				input_dir_ = 0;

				for (int i = 0; i < ColliderComponent::GetCount(); ++i)
				{
					ColliderComponent* check_against = ColliderComponent::GetInstance(i);

					if (check_against == this->collider_) continue;

					if (collider_->CollidesWith(check_against))
					{
						ColliderComponent::Hit2D* hit = collider_->Intersects(check_against);

						if (hit)
						{

							if (Equals(hit->normal.x, -1) && hit->delta.x < -1.1f) //Left
							{
								input_dir_ = 1;
							}
							if (Equals(hit->normal.x, 1) && hit->delta.x > 1.1f) //Right
							{
								input_dir_ = -1;
							}
						}
					}
				}
				
			}

			void GoombaActor::Walk()
			{
				const int input_dir = 0; //left = -1, right = +1, left+right = 0, none = 0
				
				transform_->velocity.x = input_dir * (max_speed_ * DeltaTime());
			}
		}
	}
}
