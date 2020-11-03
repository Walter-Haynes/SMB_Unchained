#include "precomp.h"

#include <Actor.h>

namespace Game
{
	namespace Prefabs
	{
		namespace Actors
		{
			Actor::Actor()
			{
				AddComponent(transform_ = new TransformComponent());
				AddComponent(renderer_ = new RendererComponent(new Sprite(new Surface("assets/PowerTile.png"), 1)));
				AddComponent(collider_ = new ColliderComponent());
				collider_->bounds = *new vec2(renderer_->sprite->GetWidth() * PIXELS_TO_UNITS,
				                              renderer_->sprite->GetHeight() * PIXELS_TO_UNITS);
			}
			Actor::Actor(Sprite* sprite)
			{
				AddComponent(transform_ = new TransformComponent());
				AddComponent(renderer_ = new RendererComponent(sprite));
				AddComponent(collider_ = new ColliderComponent());
				collider_->bounds = *new vec2(renderer_->sprite->GetWidth() * PIXELS_TO_UNITS,
				                              renderer_->sprite->GetHeight() * PIXELS_TO_UNITS);
			}
			Actor::Actor(Sprite* sprite, const vec2 bounds)
			{
				AddComponent(transform_ = new TransformComponent());
				AddComponent(renderer_ = new RendererComponent(sprite));
				AddComponent(collider_ = new ColliderComponent());
				collider_->bounds = bounds;
			}

			Actor::~Actor()
			{
				RemoveComponent(transform_);
				delete(transform_);
				transform_ = nullptr;
				
				
				RemoveComponent(renderer_);
				delete(renderer_);
				renderer_ = nullptr;
				
				
				RemoveComponent(collider_);
				delete(collider_);
				collider_ = nullptr;
				

				printf("Actor Destroyed");
			}

			void Actor::Kill()
			{
				
			}

			float Actor::Gravity() const
			{
				return DEFAULT_GRAVITY_;
			}

			void Actor::ApplyGravity() const
			{
				transform_->velocity.y += (Gravity() * DeltaTime());
			}


			void Actor::ResolveIntersects()
			{
				for (int i = 0; i < ColliderComponent::GetCount(); ++i)
				{
					ColliderComponent* check_against = ColliderComponent::GetInstance(i);

					//TODO: Check based on tags / collision matrix.

					//Skip own colliders.
					if (check_against == this->collider_) continue;

					//Skip triggers.
					if (check_against->is_trigger) continue;

					//return true if the collider we're checking against collides with the player's "ground check collider".
					if (collider_->CollidesWith(check_against))
					{
						//TODO: Get collision point from colliders.

						ColliderComponent::Hit2D* hit = collider_->Intersects(check_against);

						if (hit)
						{
							if (Equals(hit->normal.y, 1)) //Down
							{
								transform_->velocity.y = 0;
							}
							if (Equals(hit->normal.y, -1)) //Up
							{
								transform_->velocity.y = 0;

								transform_->position.y -= hit->delta.y + 1;
							}

							//Bug: We check the delta with horizontal checks for now (hit->delta.length() > 1.1f)
							//	 This is a hack, I'm doing it for now as I'm having issues with left/right collision when walking over gaps in tiles.


							if (Equals(hit->normal.x, -1) && hit->delta.x < -1.1f) //Left
							{
								//Stop movement in that direction.
								transform_->velocity.x = 0;

								//Translate out of the intersect.
								transform_->position.x -= (hit->delta.x + 1);
							}
							if (Equals(hit->normal.x, 1) && hit->delta.x > 1.1f) //Right
							{
								//Stop movement in that direction.
								transform_->velocity.x = 0;

								//Translate out of the intersect.
								transform_->position.x -= (hit->delta.x - 1);
							}

							//Debug Collisions
							check_against->DebugBounds(0xF00FFFF);

							const vec2 end_screen_pos = Engine::Managers::RenderManager::Instance()->ConvertWorldToScreen(hit->contact - hit->delta) *
								UNITS_TO_PIXELS;

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