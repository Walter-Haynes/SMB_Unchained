#pragma once

#include <Component.h>

#include <TransformComponent.h>

#include <RenderManager.h>

namespace Engine
{
	namespace Components
	{
		//TODO: Add some constructors.

		class ColliderComponent final : public Component, public Utilities::Instancer<ColliderComponent>
		{
		public:
			struct Hit2D
			{
				//ColliderComponent collider;
				vec2 contact;
				vec2 delta;
				vec2 normal;
			};
			
			vec2 bounds = *new vec2(1,1);
			vec2 offset;

			vec2* GetExtends()
			{
				if (extends_) return extends_;

				return (extends_ = new vec2(bounds * 0.5f));
			}

			TransformComponent* GetTransform()
			{
				if (transform_)
				{
					return transform_;
				}

				if ((transform_ = GetParent()->GetComponent<TransformComponent>()) == nullptr)
				{
					printf("Whine whine, doesn't have a TransformComponent, etc");
				}

				return transform_;
			}

			bool CollidesWith(const vec2& point);
			bool CollidesWith(ColliderComponent* other);

			Hit2D* Intersects(ColliderComponent* other);

			void DebugBounds(const Tmpl8::Pixel color);

		private:
			TransformComponent* transform_ = nullptr;
			vec2* extends_ = nullptr;

			vec2 Centre();

			vec2 OffsetCentre();
		};
	}
}
