#include "precomp.h"


#include <iostream>
#include <sstream> 
#include <string>


#include <SceneManager.h>


#include "SurfaceTile.h"
using Game::Prefabs::Tiles::SurfaceTile;

namespace Engine
{
	namespace Managers
	{

		void SceneManager::LoadScene(char scene[])//const std::string &scene)
		{
			current_scene = new Scene();

			const auto scene_length = GetStringSize(scene);

			bool entity_open = false;
			bool vec2_open = false;

			vec2 pos;

			std::string x;
			std::string y;

			bool set_y = false;

			for (auto i = 0; i < scene_length; ++i)
			{
				//if (scene[i] == NULL) continue;

				if (!entity_open)
				{
					if (scene[i] == '{')
					{
						entity_open = true;
						continue;
					}
				}
				else //if entity_open
				{
					if (scene[i] == '}')
					{
						entity_open = false;

						//TODO: Tile based on string / ID
						auto* tile = new SurfaceTile();
						current_scene->AddComponent(tile);
						//std::cout << std::to_string(pos.x) << ' ' << std::to_string(pos.y) << std::endl;
						tile->SetPosition(pos);

						continue;
					}
					else if (scene[i] == '[')
					{
						vec2_open = true;

						continue;
						//continue;
					}

					if (vec2_open)
					{
						if (scene[i] == ']')
						{
							vec2_open = false;

							if (set_y) //set Y
							{
								pos.y = std::stoi(y);

								y = "";
							}
							set_y = false;

							continue;
						}
						else if (scene[i] == ',')
						{
							set_y = true;

							pos.x = std::stoi(x);

							x = "";
							continue;
						}

						if (scene[i] == '-' || isdigit(scene[i]))
						{
							if (!set_y) //Set X
							{
								x += scene[i];
							}
							else //Set Y
							{
								y += scene[i];
							}
						}
					}
				}
			}

		}


		void SceneManager::LoadSceneAdditive(char subscene[])
		{

		}

		void SceneManager::CloseAllScenes()
		{

		}

		char* SceneManager::CharArrayPlusChar(const char* array, char c)
		{
			size_t sz = std::strlen(array);
			char* s = new char[sz + 2];

			std::strcpy(s, array);
			s[sz] = c;
			s[sz + 1] = '\0';

			return (s);
		}

		size_t SceneManager::GetStringSize(const char* s)
		{
			size_t size = 0;

			while (*s++) ++size;

			return size;
		}
	}
}
