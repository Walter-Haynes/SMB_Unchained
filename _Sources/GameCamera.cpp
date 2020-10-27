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

				const float speed = DeltaTime() * (Input()->GetKeyDown("Special") ? 8.0f : 2.0f);

				if (Input()->GetKeyDown("Up"))
				{
					cam_pos.y -= speed;
				}
				if (Input()->GetKeyDown("Down"))
				{
					cam_pos.y += speed;
				}
				if (Input()->GetKeyDown("Left"))
				{
					cam_pos.x -= speed;
				}
				if (Input()->GetKeyDown("Right"))
				{
					cam_pos.x += speed;
				}
				RenderManager::Instance()->GetMainCamera()->SetCameraPosition(cam_pos);
			}
		}

		
	}
}
