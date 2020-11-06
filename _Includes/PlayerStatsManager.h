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

			void AddLives(const unsigned int count);
			void SetLives(const unsigned int lives);
			unsigned int GetLives() const;

			void AddScore(const unsigned int count);
			void SetScore(const unsigned int score);
			unsigned int  GetScore() const;

			void AddCoins(const unsigned int count);
			void SetCoins(const unsigned int coins);
			unsigned int GetCoins() const;

		private:
			int game_time_ = 0; //30.000?
			
			unsigned int lives_ = 3;
			unsigned int score_ = 0;
			unsigned int coins_ = 0;
		};
	}
}