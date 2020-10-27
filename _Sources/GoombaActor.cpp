#include "precomp.h"

#include "GoombaActor.h"

namespace Game
{
	namespace Prefabs
	{
		namespace Actors
		{
			GoombaActor::GoombaActor() : Actor(new Sprite(new Surface("assets/Actors/GoombaActor.png"), 1))
			{
				//AddComponent(ground_check_collider_ = new ColliderComponent());
				//ground_check_collider_->bounds = *new vec2(1.0f, 1.0f);
				//ground_check_collider_->offset = *new vec2(0, 0.25f);
			}
		}
	}
}
