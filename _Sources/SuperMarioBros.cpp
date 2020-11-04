#include "precomp.h"

#include <SuperMarioBros.h>



#include <iostream>

namespace Game
{
	#pragma region Setup

	void SuperMarioBros::SetupCamera(Surface* screen)
	{
		RenderManager()->SetMainCamera(new Camera(screen));

		RenderManager()->GetMainCamera()->GetTransform()->position.y -= SCREEN_HEIGHT_UNITS - 1;
	}

	void SuperMarioBros::SetupInputs()
	{
		Input()->RegisterNewKey(26, "Up");      //W
		Input()->RegisterNewKey(22, "Down");    //S
		
		Input()->RegisterNewKey(4,  "Left");    //A
		Input()->RegisterNewKey(7,  "Right");   //D
		
		Input()->RegisterNewKey(44, "Special"); //Space
	}

	void SuperMarioBros::SetupWorld()
	{
		std::string level;
		
		level += "{[0 ,0]} {[1 ,0]} {[2 ,0]} {[3 ,0]} {[4 ,0]} {[5 ,0]} {[6 ,0]} {[7 ,0]} {[8 ,0]} {[9 ,0]}";
		level += "{[10,0]} {[11,0]} {[12,0]} {[13,0]} {[14,0]} {[15,0]} {[16,0]} {[17,0]} {[18,0]} {[19,0]}";
		level += "{[20,0]} {[21,0]} {[22,0]} {[23,0]} {[24,0]} {[25,0]} {[26,0]} {[27,0]} {[28,0]} {[29,0]}";

		level += "{[30,0]} {[31,0]} {[32,0]} {[33,0]} {[34,0]} {[35,0]} {[36,0]} {[37,0]} {[38,0]} {[39,0]}";
		level += "{[40,0]} {[41,0]} {[42,0]} {[43,0]} {[44,0]} {[45,0]} {[46,0]} {[47,0]} {[48,0]} {[49,0]}";
		level += "{[50,0]} {[51,0]} {[52,0]} {[53,0]} {[54,0]} {[55,0]} {[56,0]} {[57,0]} {[58,0]} {[59,0]}";
		
		level += "{[0 ,-1]}";
		level += "{[5 ,-1]}";
		level += "{[10 ,-1]}";

		char char_array[1024];
		strcpy(char_array, level.c_str());

		SceneManager()->LoadScene(char_array);
	}


	#pragma endregion Setup
	
	#pragma region Loop
	
	void SuperMarioBros::Start() const
	{
		SetupInputs();
		SetupWorld();

		power_tile_test_->GetTransform()->position = *new vec2(4, -3);

		player_actor_->GetTransform()->position = *new vec2(1, -1);
		//player_actor_->Start();

		coin_->GetTransform()->position = *new vec2(6, -1);


		goomba_actor_->GetTransform()->position = *new vec2(7, -2);
	}

	void SuperMarioBros::Update() const
	{
		RenderManager()->ClearScreen();

		player_actor_->Update();

		game_camera_->Update();

		coin_->Update();

		if(goomba_actor_ != nullptr)
		{
			goomba_actor_->Update();
		}
		
		RenderManager()->DrawAllRenderers();
	}

	void SuperMarioBros::Stop() const
	{
		player_actor_->Stop();
	}

	#pragma endregion Loop
	
}