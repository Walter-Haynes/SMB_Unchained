#pragma once

#include "Behaviour.h"
using Engine::Behaviour;

#include "TransformComponent.h"
using Engine::Components::TransformComponent;
#include "RendererComponent.h"
using Engine::Components::RendererComponent;
#include "ColliderComponent.h"
using Engine::Components::ColliderComponent;

#include "MathUtilities.h"
using Engine::MathUtilities::PIXELS_TO_UNITS;

namespace Game
{
	namespace Prefabs
	{
		namespace Actors
		{
			class Actor : public Behaviour
			{
			public:
				Actor();
				Actor(Sprite* sprite);
				Actor(Sprite* sprite, const vec2 bounds);

				#pragma region Default Components
				
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

				#pragma endregion  Default Components
				
			protected:
				TransformComponent* transform_;
				RendererComponent*  renderer_;
				ColliderComponent*  collider_;

				/*!
				 * Override this if you want gravity other than the default.
				 *      @return The gravity variable
				 */
				virtual float Gravity() const;

				void ApplyGravity() const;

			private:
				const float DEFAULT_GRAVITY_ = 9.8f;
				
			};
		}
	}
}