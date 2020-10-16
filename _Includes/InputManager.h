#pragma once

#include <Manager.h>

#include <map>
#include <string>

using Tmpl8::vec2;
using Tmpl8::Surface;

namespace Engine
{
	namespace Managers
	{
		class InputManager final : public Utilities::Manager<InputManager>
		{
		public:
			void RegisterNewKey(int id, const std::string& name);
			
			bool GetKeyDown(const std::string& name);

			vec2 GetMousePosition() const;
			void SetMousePosition(vec2 position);

			void SetKeyUp(int key);
			void SetKeyDown(int key);

			private:
				std::map<std::string, int> key_lookup_table_;
				std::map<int, bool> states_lookup_table;
			
				vec2 mouse_position_;
		};
	}
}
