#include "precomp.h"

#include <PlayerStatsManager.h>

#include <iostream>

namespace Game
{
	namespace Managers
	{
		
		void PlayerStatsManager::AddLives(const unsigned count)
		{
			lives_ += count;
		}
		void PlayerStatsManager::SetLives(const unsigned lives)
		{
			lives_ = lives; 
		}
		unsigned PlayerStatsManager::GetLives() const
		{
			return lives_;
		}

		void PlayerStatsManager::AddScore(const unsigned count)
		{
			score_ += count;
		}
		void PlayerStatsManager::SetScore(const unsigned score)
		{
			score_ = score;
		}
		unsigned PlayerStatsManager::GetScore() const
		{
			return score_;
		}


		void PlayerStatsManager::AddCoins(const unsigned count)
		{
			coins_ += count;
			std::cout << "Coins = " << coins_ << std::endl;
		}
		void PlayerStatsManager::SetCoins(const unsigned int count)
		{
			coins_ = count;
		}
		unsigned int PlayerStatsManager::GetCoins() const
		{
			return coins_;
		}
		
	}
}