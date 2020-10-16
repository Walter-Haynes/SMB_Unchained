#include "precomp.h"

#include <TransformComponent.h>

#include "GameSettings.h"

namespace Engine
{
	namespace Components
	{
		vec2 TransformComponent::GetPixelPos() const
		{
			return position * Core::PIXELS_PER_UNIT;
		}

		vec2 TransformComponent::GetDirection() const
		{
			return direction_;
		}
	}
}
