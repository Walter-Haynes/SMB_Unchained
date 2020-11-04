#include "precomp.h"

#include <Pickup.h>

using Tmpl8::vec2;

namespace Game
{
	namespace Prefabs
	{
		namespace Pickups
		{
			Pickup::Pickup()
			{
				AddComponent(transform_ = new TransformComponent());
				AddComponent(renderer_ = new RendererComponent(new Sprite(new Surface("assets/DefaultSprite.png"), 1)));
				AddComponent(collider_ = new ColliderComponent());
				collider_->bounds = *new vec2(renderer_->sprite->GetWidth() * PIXELS_TO_UNITS,
					renderer_->sprite->GetHeight() * PIXELS_TO_UNITS);
				collider_->is_trigger = true;
			}
			Pickup::Pickup(Sprite* sprite)
			{
				AddComponent(transform_ = new TransformComponent());
				AddComponent(renderer_ = new RendererComponent(sprite));
				AddComponent(collider_ = new ColliderComponent());
				collider_->bounds = *new vec2(renderer_->sprite->GetWidth() * PIXELS_TO_UNITS,
					renderer_->sprite->GetHeight() * PIXELS_TO_UNITS);
				collider_->is_trigger = true;
			}
			Pickup::Pickup(Sprite* sprite, const vec2 bounds)
			{
				AddComponent(transform_ = new TransformComponent());
				AddComponent(renderer_ = new RendererComponent(sprite));
				AddComponent(collider_ = new ColliderComponent());
				collider_->bounds = bounds;
			}

			Pickup::~Pickup()
			{
				/*
				if (transform_)
				{
					RemoveComponent(transform_);
					delete(transform_);
					transform_ = nullptr;
				}

				if (renderer_)
				{
					RemoveComponent(renderer_);
					delete(renderer_);
					renderer_ = nullptr;
				}

				if (collider_)
				{
					RemoveComponent(collider_);
					delete(collider_);
					collider_ = nullptr;
				}
				*/

				RemoveComponent(transform_);
				delete(transform_);
				transform_ = nullptr;


				RemoveComponent(renderer_);
				delete(renderer_);
				renderer_ = nullptr;


				RemoveComponent(collider_);
				delete(collider_);
				collider_ = nullptr;


				printf("Pickup Destroyed");
			}

			void Pickup::Collect()
			{
				
			}

			void Pickup::SetPosition(const vec2 position)
			{
				transform_->position = position;
			}
		}
	}
}