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
		//TODO: Make a custom Map if I can find the time.
		
		class InputManager final : public Utilities::Manager<InputManager>
		{
		public:
			void RegisterNewKey(int key, const std::string& name);

			/*!
			 *  Returns the current state of the key [name].
			 *
			 *      @param [in] name: Name of what key to check.
			 *
			 *      @return True when the key is held down, False if it's not.
			 */
			bool GetKey(const std::string& name);
			/*!
			 *  Returns true when the state of the key [name] changes to "NOT being pressed".
			 *
			 *      @param [in] name: Name of what key to check.
			 *
			 *      @return True when the key's state switched to "NOT being pressed" this frame.
			 */
			bool GetKeyUp(const std::string& name);
			/*!
			 *  Returns true when the state of the key [name] changes to "being pressed".
			 *
			 *      @param [in] name: Name of what key to check.
			 *
			 *      @return True when the key's state switched to "being pressed" this frame.
			 */
			bool GetKeyDown(const std::string& name);

			vec2 GetMousePosition() const;
			void SetMousePosition(vec2 position);

			
			void SetKeyUp(int key) const;
			void SetKeyDown(int key) const;
			//The reason I've separated these into SetKeyUp and SetKeyDown, instead of SetKey with an overload is simply because I find it more readable.

		private:
			std::map<std::string, int> key_lookup_table_;
			
			std::map<int, bool>* states_lookup_table_current_ = new std::map<int, bool>;
			std::map<int, bool>* states_lookup_table_last_ = new std::map<int, bool>;
		
			vec2 mouse_position_;

			static bool GetState(std::map<int, bool>* states_table, int key);
			static void SetState(std::map<int, bool>* states_table, int key, bool value);
		};
	}
}
