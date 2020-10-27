#pragma once

#include <Manager.h>
using Engine::Utilities::Manager;

namespace Game
{
	namespace Managers
	{
		class GameStateManager final : public Manager<GameStateManager>
		{
		public:
			enum class GameState
			{
				main_menu, playing, level_transition, game_over, time_out
			} game_state = GameState::playing; //TODO: Switch to main_menu default state

		};
	}
}