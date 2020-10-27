#pragma once

#include <Behaviour.h>
using Engine::Behaviour;

#include <TransformComponent.h>
using Engine::Components::TransformComponent;
#include <RendererComponent.h>
using Engine::Components::RendererComponent;
#include <ColliderComponent.h>
using Engine::Components::ColliderComponent;

namespace Game
{
	namespace Prefabs
	{
		namespace Pickups
		{
			class Pickup : public Behaviour
			{
			public:
				Pickup();
				Pickup(Sprite* sprite);

				virtual ~Pickup() = default;

				/*!
				 *  Sets the pickup's position.
				 *
				 *      @param [in] position: The pickups's new position IN UNITS.
				 */
				virtual void SetPosition(vec2 position);

				virtual TransformComponent* GetTransform()
				{
					return transform_;
				}

				virtual RendererComponent* GetRenderer()
				{
					return renderer_;
				}

				virtual ColliderComponent* GetCollider()
				{
					return collider_;
				}

			protected:
				TransformComponent* transform_;
				RendererComponent* renderer_;
				ColliderComponent* collider_;

			};
		}
	}
}
