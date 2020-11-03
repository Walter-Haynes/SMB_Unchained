#pragma once

#include <Scene.h>

#include <Manager.h>
using Engine::Utilities::Manager;

namespace Engine
{
	namespace Managers
	{
		/*!
		 *  Manages Loading and Unloading of (multiple) Scenes.
		 */
		class SceneManager : public Manager<SceneManager>
		{
		public:
			Scene* current_scene = nullptr;

			void LoadScene(char scene[]);
			void LoadSceneAdditive(char subscene[]);

			void CloseAllScenes();

			static char* CharArrayPlusChar(const char* array, char c);

			static size_t GetStringSize(const char* s);
		};
	}
}

