#pragma once

#include <Behaviour.h>
using Engine::Behaviour;

#include <TransformComponent.h>
using Engine::Components::TransformComponent;
#include <RendererComponent.h>
using Engine::Components::RendererComponent;

namespace Game
{
	namespace Prefabs
	{
		namespace Tiles
		{
			class Tile : public Behaviour
			{
			public:
				Tile();
				Tile(Sprite* sprite);

				virtual ~Tile() = default;

				/*!
				 *  Sets the tile's position.
				 *
				 *      @param [in] position: The tile's new position IN UNITS.
				 */
				virtual void SetPosition(vec2 position);

				virtual TransformComponent* GetTransform()
				{
					return transform_;
				}

				virtual RendererComponent* GetRenderer()
				{
					return renderer_;
				}

			protected:
				TransformComponent*
					transform_;

				RendererComponent*
					renderer_;
				
			};
		}
	}
}
