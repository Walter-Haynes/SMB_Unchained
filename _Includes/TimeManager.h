#pragma once

#include <Manager.h>

namespace Engine
{
	namespace Managers
	{
		class TimeManager final : public Utilities::Manager<TimeManager>
		{
			public:
				float GetDeltaTime() const;
				void SetDeltaTime(float value);

			private:
				float delta_time_ = 0.0f;
		};
	}
}