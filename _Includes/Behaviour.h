#pragma once

#include <TimeManager.h>
using Engine::Managers::TimeManager;

#include <Component.h>

namespace Engine
{
	/*!
	 *  Inherit from this if you want a component that executes logic on the Start, Update, or Stop events.
	 */
	class Behaviour : public Component
	{
	public:
		//virtual ~Behaviour() = default;
		virtual void Start() {}
		virtual void Update() {}
		virtual void Stop() {}

	protected:
		/*!
		 *  Shortcut to the GetDeltaTime value of the Time Manager
		 */
		static float DeltaTime()
		{
			return TimeManager::Instance()->GetDeltaTime();
		}
	};
}