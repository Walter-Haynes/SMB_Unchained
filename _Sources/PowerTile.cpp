#include "precomp.h"

#include "PowerTile.h"

namespace Game
{
	namespace Prefabs
	{
		namespace Tiles
		{
			PowerTile::PowerTile() : Tile(new Sprite(new Surface("assets/Tiles/PowerTile.png"), 1))
			{
				AddComponent(collider_ = new ColliderComponent());
				collider_->bounds = *new vec2(1, 1);
			}
		}
	}
}