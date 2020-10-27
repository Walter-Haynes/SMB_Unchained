#include "precomp.h"

#include <Tile.h>

using Tmpl8::vec2;

namespace Game
{
	namespace Prefabs
	{
		namespace Tiles
		{
			Tile::Tile()
			{
				AddComponent(transform_ = new TransformComponent());
				AddComponent(renderer_ = new RendererComponent(new Sprite(new Surface("assets/Tiles/DefaultTile.png"), 1)));
			}
			Tile::Tile(Sprite* sprite)
			{
				AddComponent(transform_ = new TransformComponent());
				AddComponent(renderer_ = new RendererComponent(sprite));
			}

			void Tile::SetPosition(const vec2 position)
			{
				transform_->position = position;
			}
		}
	}
}