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
		level += "{[0 ,-1]}";
		level += "{[5 ,-1]}";

		char char_array[1024];
		strcpy(char_array, level.c_str());

		SceneManager()->LoadScene(char_array);
	}


	#pragma endregion Setup
	
	#pragma region Loop
	
	void SuperMarioBros::Start()
	{
		SetupInputs();
		SetupWorld();

		power_tile_test_->GetTransform()->position = *new vec2(4, -3);

		player_actor_->Start();
		player_actor_->GetTransform()->position = *new vec2(1, -1);
	}

	void SuperMarioBros::Update()
	{
		RenderManager()->ClearScreen();

		player_actor_->Update();
		
		RenderManager()->DrawAllRenderers();
	}

	void SuperMarioBros::Stop()
	{
		player_actor_->Stop();
	}

	#pragma endregion Loop
	
}