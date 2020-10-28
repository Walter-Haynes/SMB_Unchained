#pragma once

#include <Component.h>

using Tmpl8::vec2;

namespace Engine
{
	namespace Components
	{
		//TODO: redo directions, remove rotation.
		//TODO: Screen/World Positions.
		
		
		class TransformComponent final : public Component
		{
		public:
			vec2 position;
		
			vec2 velocity = *new vec2(0, 0);

			TransformComponent(const vec2 pos = *new vec2(0, 0)) : Component(),  position(pos)
			{ }
			virtual ~TransformComponent() = default;

			vec2 GetPositionPixels() const;
			vec2 GetPositionUnits() const; //just for ease of use, you can do it directly via position as well.

			void Update();

			void Translate(vec2 translation);
			void Translate(float x, float y);
			
		};

	}
}