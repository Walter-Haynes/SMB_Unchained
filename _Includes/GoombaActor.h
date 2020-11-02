#pragma once

#include "Actor.h"

#include "InputManager.h"
using Engine::Managers::InputManager;

namespace Game
{
	namespace Prefabs
	{
		namespace Actors
		{
			class GoombaActor final : public Actor
			{
			public:
				GoombaActor();

				//void Start() override;
				void Update() override;
				//void Stop() override;

			private:
				float max_speed_ = 15.0f; //TODO: Maybe move to base Actor?

				int input_dir_ = -1;
				
				//bool is_going_left_ = false;
				
				void CheckWallCollisions();
				
				void Walk();

			};
		}
	}
}