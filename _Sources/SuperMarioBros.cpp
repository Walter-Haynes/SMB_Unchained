//#include "precomp.h" // include this first in every .cpp file

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
			if (Input()->GetKeyDown("Special"))
			{
				const vec2 cam_pos = RenderManager()->GetMainCamera()->GetCameraPosition();

				RenderManager()->GetMainCamera()->SetCameraPosition(
					cam_pos.x + (3 * DeltaTime()), 
					cam_pos.y - (3 * DeltaTime()));
			}
		}
		
		RenderManager()->DrawAllRenderers();
	}

	void SuperMarioBros::Stop()
	{

	}

	/*
	void Game::KeyUp(const int key)
	{
		switch (key)
		{
		case 4:  //A
			Input()->left.is_pressed = false;
			break;
		case 7:  //D
			Input()->right.is_pressed = false;
			break;
		case 26: //W
			Input()->jump.is_pressed = false;
			break;
		case 44: //SPACE
			Input()->special.is_pressed = false;
			break;
		default:
			break;
		}
	}
	void Game::KeyDown(const int key)
	{
		//Cache the time between no and first input, and use it as a seed for RNGs
		if (is_first_input_)
		{
			seed_locked_in_ = true;
			is_first_input_ = false;

			printf("Set seed");
		}

		switch (key)
		{
		case 4:  //A
			Input()->left.is_pressed = true;
			break;
		case 7:  //D
			Input()->right.is_pressed = true;
			break;
		case 26: //W
			Input()->jump.is_pressed = true;
			break;
		case 44: //SPACE
			Input()->special.is_pressed = true;
			break;
		default:
			break;
		}
	}

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