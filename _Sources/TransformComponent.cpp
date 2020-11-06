#include "precomp.h"

#include <TransformComponent.h>

#include <GameSettings.h>
#include <TimeManager.h>
using Engine::Managers::TimeManager;

namespace Engine
{
	namespace Components
	{
		vec2 TransformComponent::GetPositionPixels() const
		{
			return position * PIXELS_PER_UNIT;
		}
		vec2 TransformComponent::GetPositionUnits() const
		{
			return position;
		}

		void TransformComponent::Update()
		{
			position += (velocity * TimeManager::Instance()->GetDeltaTime());
		}

		/*!
		 *  Translates the transform component.
		 *
		 *      @param [in] translation: The translation IN UNITS PER FRAME
		 */
		void TransformComponent::Translate(const vec2 translation)
		{
			position += translation;
		}
		/*!
		 *  Translates the transform component.
		 *
		 *      @param [in] x: Horizontal translation IN UNITS PER FRAME
		 *      @param [in] y: Vertical translation IN UNITS PER FRAME
		 */
		void TransformComponent::Translate(const float x, const float y)
		{
			position.x += x;
			position.y += y;
		}
		
	}
}
