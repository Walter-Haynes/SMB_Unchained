#pragma once

#include <Pickup.h>
using Game::Prefabs::Pickups::Pickup;

namespace Game
{
	namespace Prefabs
	{
		namespace Pickups
		{

			class CoinPickup final : public Pickup
			{
			public:
				CoinPickup();
				
				void Update() override;

				void CollectIfTriggered();
				
				void Collect() override;
			};
		}
	}
}
