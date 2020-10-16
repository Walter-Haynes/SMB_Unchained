#pragma once

#include <TimeManager.h>
#include <Component.h>

using Engine::Managers::TimeManager;

namespace Engine
{
	namespace Components
	{
		/*!
		 *  Inherit from this if you want to use Start, Update, Stop behaviour.
		 */
		class Behaviour : public Component
		{
		public:
			//virtual ~Behaviour() = default;
			virtual void Start() {}
			virtual void Update() {}
			virtual void Stop() {}
		
		protected:
			/// <summary> Shortcut to the GetDeltaTime value of the Time Manager. </summary>
			static float DeltaTime()
			{
				return TimeManager::Instance()->GetDeltaTime();
			}
		};
	}
}