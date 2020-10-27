#include "precomp.h"

#include "BrickTile.h"

namespace Game
{
	namespace Prefabs
	{
		namespace Tiles
		{
			BrickTile::BrickTile() : Tile(new Sprite(new Surface("assets/Tiles/BrickTile.png"), 1))
			{
				AddComponent(collider_ = new ColliderComponent());
				collider_->bounds = *new vec2(1, 1);
			}
		}
	}
}