#pragma once

#include <Component.h>

namespace Engine
{
	namespace Components
	{
		class TransformComponent final : public Component
		{
		public:
			vec2 position;
			float rotation = 0;
		
			vec2 velocity = *new vec2(0, 0);

			TransformComponent(const vec2 pos = *new vec2(0, 0)) : Component(),  position(pos)
			{ }
			virtual ~TransformComponent() = default;

			vec2 GetPixelPos() const;

			vec2 GetDirection();

			/*
			vec2 GetScreenPosition()
			{
				//return Managers::RenderManager::Instance()->WorldToScreen(position);
			}
			
			vec2 GetWorldPosition() const
			{
				return position;
			}
			*/

		private:
			vec2 direction_ = *new vec2(0, 0);
		};

	}
}