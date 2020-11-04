#include "precomp.h"

#include <CoinPickup.h>

#include "PlayerStatsManager.h"
using Game::Managers::PlayerStatsManager;

#include "SuperMarioBros.h"

#include "PlayerActor.h"
using Game::Prefabs::Actors::PlayerActor;

using Tmpl8::vec2;

namespace Game
{
	namespace Prefabs
	{
		namespace Pickups
		{
			CoinPickup::CoinPickup() : Pickup(new Sprite(new Surface("assets/Pickups/CoinPickup.png"), 1))
			{
			}

			void CoinPickup::Update()
			{
				CollectIfTriggered();
			}

			void CoinPickup::CollectIfTriggered()
			{
				if (PlayerActor::Instance()->GetCollider()->CollidesWith(collider_))
				{
					this->Collect();
				}
			}

			void CoinPickup::Collect()
			{
				PlayerStatsManager::Instance()->AddCoins(1);

				SuperMarioBros::Instance()->DeleteGoombas();
				delete(this);
			}
		}
	}
}