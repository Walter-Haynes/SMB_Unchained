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
				AddComponent(renderer_  = new RendererComponent(new Sprite(new Surface("assets/DefaultSprite.png"), 1)));
				AddComponent(collider_  = new ColliderComponent());
				collider_->bounds = *new vec2(1, 1);
			}
			Pickup::Pickup(Sprite* sprite)
			{
				AddComponent(transform_ = new TransformComponent());
				AddComponent(renderer_  = new RendererComponent(sprite));
				AddComponent(collider_  = new ColliderComponent());
				collider_->bounds = *new vec2(1, 1);
			}

			void Pickup::SetPosition(const vec2 position)
			{
				transform_->position = position;
			}
		}
	}
}