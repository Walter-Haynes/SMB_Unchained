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
			class SurfaceTile final : public Tile
			{
			public:
				SurfaceTile();
				
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

