#include "precomp.h"

#include "SurfaceTile.h"

namespace Game
{
	namespace Prefabs
	{
		namespace Tiles
		{
			SurfaceTile::SurfaceTile() : Tile(new Sprite(new Surface("assets/Tiles/SurfaceTile.png"), 1))
			{
				AddComponent(collider_ = new ColliderComponent());
				collider_->bounds = *new vec2(1, 1);
			}
		}
	}
}