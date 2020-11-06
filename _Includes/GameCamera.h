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
			//float min_x_ = 0.0;
			//float min_y_ = 10.0;

			/*!
			 *  The minimum positions on each axis (so the camera doesn't go below the ground for example)
			 */
			vec2 min_clamp_ = vec2(0.0f, 3.0f);

			vec2 offset_ = vec2(-5, -10);
			
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
