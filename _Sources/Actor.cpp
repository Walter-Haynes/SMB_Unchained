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

			void Actor::ApplyGravity() const
			{
				transform_->velocity.y += gravity_ * DeltaTime();
			}
		}
	}
}