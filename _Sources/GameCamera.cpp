#include "precomp.h"

#include "GameCamera.h"

#include "RenderManager.h"
using Engine::Managers::RenderManager;

#include <SuperMarioBros.h>
using Game::SuperMarioBros;

namespace Game
{
	namespace Prefabs
	{
		void GameCamera::Update()
		{
			if(CurrentGameState() == GameStateManager::GameState::playing)
			{
				vec2 cam_pos = RenderManager::Instance()->GetMainCamera()->GetCameraPosition();

				const TransformComponent* target = PlayerActor::Instance()->GetTransform();

				cam_pos = target->position + offset_;
				
				//cam_pos.x = Min((target->position.x + offset_.x), min_x_);
				//cam_pos.y = Min((target->position.y + offset_.y), min_y_);

				cam_pos.x <= min_clamp_.x ? min_clamp_.x : cam_pos.x;
				cam_pos.y <= min_clamp_.y ? min_clamp_.y : cam_pos.y;

				
				
				RenderManager::Instance()->GetMainCamera()->SetCameraPosition(cam_pos);
			}
		}

		
	}
}
