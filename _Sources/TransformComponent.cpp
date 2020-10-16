#include "precomp.h"

#include <TransformComponent.h>

namespace Engine
{
	namespace Components
	{
		vec2 TransformComponent::GetPixelPos() const
		{
			return position * Core::PIXELS_PER_UNIT;
		}

		vec2 TransformComponent::GetDirection()
		{
			direction_.x = cos(rotation * Math::DEGTORAD);
			direction_.y = sin(rotation * Math::DEGTORAD);

			return direction_;
		}
	}
}