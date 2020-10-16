#include "precomp.h"

#include <TimeManager.h>

namespace Engine 
{
	namespace Managers
	{
		float TimeManager::GetDeltaTime() const
		{
			//Convert to seconds instead of milliseconds.
			return delta_time_ / 1000;
		}
		void TimeManager::SetDeltaTime(const float value)
		{
			delta_time_ = value;
		}
	}
}