#pragma once


#include <TimeManager.h>
using Engine::Managers::TimeManager;
#include <InputManager.h>
using Engine::Managers::InputManager;
#include <RenderManager.h>
using Engine::Managers::RenderManager;


#include <List.h>
using Engine::Types::List;


namespace Core
{
	class SuperMarioBros final
	{
		public:
			enum class GameState
			{
				main_menu, playing, level_transition, game_over, time_out
			} game_state = GameState::playing; //TODO: Switch to main_menu default state

			static void SetTarget(Surface* screen);
		
			void Start();
			void Update();
			void Stop();

			#pragma region Managers

			/*!
			*  Shortcut to the Input Manager.
			*/
			static InputManager* Input()
			{
				return InputManager::Instance();
			}

			/*!
			*  Shortcut to the Render Manager.
			*/
			static RenderManager* RenderManager()
			{
				return RenderManager::Instance();
			}

			/*!
			*  Shortcut to the Time Manager.
			*/
			static TimeManager* Time()
			{
				return TimeManager::Instance();
			}

			#pragma endregion Managers

		private:
			/*
			 * 	int game_time_ = 300000;
				int lives_ = 3;
				int score_ = 0;
				int coins_ = 0;
			 */

			static float DeltaTime()
			{
				return Time()->GetDeltaTime();
			}
	};

}