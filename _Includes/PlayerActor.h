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

			class PlayerActor final : public Actor
			{
			public:
				PlayerActor();

				//void Start() override;
				void Update() override;
				//void Stop() override;


				struct Collisions
				{
					bool left = false, right = false, up = false, down = false;

					List<ColliderComponent> colliding_colliders;
				};

			private:
				float max_speed_ = 15.0f; //TODO: Maybe move to base Actor?

				float ground_walk_acceleration_ = 60.0f, ground_run_acceleration_ = 150.0f,  air_acceleration_ = 30.0f;
				float ground_deceleration_ = 50;

				float jump_height_ = 40.0f;

				vec2 internal_velocity_;

				ColliderComponent* ground_check_collider_;

				bool IsGrounded() const;
				Collisions* CheckCollision();

				void Walk();
				void Jump();

				/*!
				 *  Pushes the player's collider out of collider's it's intersecting with.
				 */
				void ResolveIntersects();

				/*!
				 *  Shortcut to the Input Manager.
				 */
				static InputManager* Input()
				{
					return InputManager::Instance();
				}

				
			};
		}
	}
}