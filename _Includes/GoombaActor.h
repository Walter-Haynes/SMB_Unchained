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
				~GoombaActor();

				//void Start() override;
				void Update() override;
				//void Stop() override;

				void Kill() override;

			private:
				float max_speed_ = 2.0f; //TODO: Maybe move to base Actor?

				/*!
				 *  left = -1, right = +1, left+right = 0, none = 0
				 */
				int input_dir_ = -1;

				ColliderComponent* player_check_trigger_;


				bool CheckIsGrounded() const;
				void KillIfStomped();
				
				//bool is_going_left_ = false;
				
				void CheckWallCollisions();
				
				void Walk();

			};
		}
	}
}