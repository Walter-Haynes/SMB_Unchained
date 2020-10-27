#pragma once

#include <Behaviour.h>
using Engine::Behaviour;

#include "InputManager.h"
using Engine::Managers::InputManager;

#include "GameStateManager.h"
using Game::Managers::GameStateManager;

namespace Game
{
	namespace Prefabs
	{

		class GameCamera final : public Behaviour
		{
		public:
			void Update() override;

		private:
			/*!
			*  Shortcut to the Input Manager.
			*/
			static InputManager* Input()
			{
				return InputManager::Instance();
			}

			/*!
			*  Shortcut to the current Game State.
			*/
			static GameStateManager::GameState CurrentGameState()
			{
				//TODO: Change to reference.
				return GameStateManager::Instance()->game_state;
			}

		};
	}
}
