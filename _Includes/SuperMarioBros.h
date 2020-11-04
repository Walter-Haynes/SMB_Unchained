#pragma once


#include <TimeManager.h>
using Engine::Managers::TimeManager;
#include <InputManager.h>
using Engine::Managers::InputManager;
#include <RenderManager.h>
using Engine::Managers::RenderManager;
#include <SceneManager.h>
using Engine::Managers::SceneManager;


#include <List.h>
using Engine::Types::List;

#include <GameCamera.h>
using Game::Prefabs::GameCamera;
#include <PlayerActor.h>
using Game::Prefabs::Actors::PlayerActor;
#include <GoombaActor.h>
using Game::Prefabs::Actors::GoombaActor;
#include <PowerTile.h>
using Game::Prefabs::Tiles::PowerTile;

#include <CoinPickup.h>
using Game::Prefabs::Pickups::CoinPickup;


namespace Game
{

	/*!
	 *  This is the games' main class, it's responsible for setting up and calling all Managers. 
	 */
	class SuperMarioBros final : public Manager<SuperMarioBros>
	{
	public:
		static void SetupCamera(Surface* screen);

		#pragma region Loop
	
		void Start() const;
		void Update() const;
		void Stop() const;

		#pragma endregion Loop

		//Temporary
		void DeleteGoombas()
		{
			goomba_actor_ = nullptr;
		}

		void DeleteCoins()
		{
			coin_ = nullptr;
		}

		#pragma region Manager Shortcuts

		/*!
		*  Shortcut to the Input Manager.
		*/
		static InputManager* Input()
		{
			return InputManager::Instance();
		}

		/*!
		*  Shortcut to the Render Manager.
		*/
		static RenderManager* RenderManager()
		{
			return RenderManager::Instance();
		}

		/*!
		*  Shortcut to the Time Manager.
		*/
		static TimeManager* Time()
		{
			return TimeManager::Instance();
		}

		/*!
		*  Shortcut to the Scene Manager.
		*/
		static SceneManager* SceneManager()
		{
			return SceneManager::Instance();
		}

		#pragma endregion Manager Shortcuts

	private:
		GameCamera* game_camera_ = new GameCamera;

		PlayerActor* player_actor_ = new PlayerActor;

		GoombaActor* goomba_actor_ = new GoombaActor;

		CoinPickup* coin_ = new CoinPickup;

		PowerTile* power_tile_test_ = new PowerTile;

		/*!
		 *  Setup SceneManager, and loads the default scene.
		 */
		static void SetupWorld();
		
		/*!
		*  Setup all Input bindings inside this method.
		*/
		static void SetupInputs();
	};

}