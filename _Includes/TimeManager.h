#pragma once

#include <Manager.h>
using Engine::Utilities::Manager;

namespace Engine
{
	namespace Managers
	{
		/*!
		 *  Manages keeping track of all time information.
		 */
		class TimeManager final : public Manager<TimeManager>
		{
		public:
			/*!
			 *      @return The amount of time IN SECONDS it took to complete the last frame.
			 */
			float GetDeltaTime() const;
			void SetDeltaTime(float value);

		private:
			float delta_time_ = 0.0f;
		};
	}
}