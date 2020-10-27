#pragma once

#include <Tile.h>
using Game::Prefabs::Tiles::Tile;

#include <ColliderComponent.h>
using Engine::Components::ColliderComponent;

namespace Game
{
	namespace Prefabs
	{
		namespace Tiles
		{
			//TODO: Make IDestroyableTile Interface?

			class BrickTile final : public Tile
			{
			public:
				BrickTile();

				ColliderComponent* GetCollider() const
				{
					return collider_;
				}

			private:
				ColliderComponent* collider_;
			};
		}
	}
}

