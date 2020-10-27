#pragma once

#include <Manager.h>
using Engine::Utilities::Manager;

namespace Game
{
	namespace Managers
	{
		class PlayerStatsManager final : public Manager<PlayerStatsManager>
		{
		public:
			void AddLives();
			void SetLives();
			void GetLives();

			void AddScore();
			void SetScore();
			void GetScore();

			void AddCoins();
			void SetCoins();
			void GetCoins();

		private:
			int game_time_ = 0; //30.000?
			
			int lives_ = 3;
			int score_ = 0;
			int coins_ = 0;
		};
	}
}