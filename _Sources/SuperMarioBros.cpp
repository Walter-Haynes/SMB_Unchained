#include "precomp.h"

#include <SuperMarioBros.h>

namespace Core
{
	void SuperMarioBros::SetTarget(Surface* screen)
	{
		RenderManager()->SetMainCamera(new Camera(screen));
	}

	void SuperMarioBros::Start()
	{
		Input()->RegisterNewKey(4,  "Left");    //A
		Input()->RegisterNewKey(7,  "Right");   //D
		Input()->RegisterNewKey(26, "Jump");    //W
		Input()->RegisterNewKey(44, "Special"); //Space
	}

	void SuperMarioBros::Update()
	{
		RenderManager()->ClearScreen();
		
		if(game_state == GameState::playing)
		{
			/*
			if (Input()->GetKeyDown("Special"))
			{
				//printf("Special");
				
				const vec2 cam_pos = RenderManager()->GetMainCamera()->GetCameraPosition();

				RenderManager()->GetMainCamera()->SetCameraPosition(
					cam_pos.x + (3 * DeltaTime()), 
					cam_pos.y - (3 * DeltaTime()));
			}
			*/
		}
		
		RenderManager()->DrawAllRenderers();
	}

	void SuperMarioBros::Stop()
	{

	}

	/*
	void Game::CollisionTest() const
	{
		cursor_->SetPosition(RenderManager()->ScreenToWorld(Input()->GetMousePosition() * (1.0f/PIXELS_PER_UNIT)));

		bool is_colliding = false;
		
		for (int i = 0; i < AABBColliderComponent::GetCount(); ++i)
		{
			AABBColliderComponent* collider = AABBColliderComponent::GetInstance(i);
			if(collider == cursor_->GetCollider()) continue;
			
			if(collider->CollidesWith(cursor_->GetCollider()))
			{
				is_colliding = true;

				collider->DebugBounds(747474);
			}
		}

		cursor_->GetCollider()->DebugBounds(is_colliding ? 0x00FFFF : 0xFF0000);
		
	}
	*/
	
};