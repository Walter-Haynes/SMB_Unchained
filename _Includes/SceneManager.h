#pragma once

#include <Scene.h>

#include <Manager.h>

namespace Engine
{
	namespace Managers
	{
		/// <summary>
		/// Handles Loading and Unloading of (multiple) Scenes.
		/// </summary>
		class SceneManager : public Utilities::Manager<SceneManager>
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

