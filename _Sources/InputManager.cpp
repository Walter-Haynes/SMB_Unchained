#include "precomp.h"

#include <InputManager.h>

namespace Engine
{
	namespace Managers
	{
		void InputManager::RegisterNewKey(const int key, const std::string& name)
		{
			key_lookup_table_.insert({name, key});
			states_lookup_table.insert({ key, false });
		}

		bool InputManager::GetKeyDown(const std::string& name)
		{
			const auto keys_iterator = key_lookup_table_.find(name);

			if (keys_iterator == key_lookup_table_.end())
			{
				//TODO: throw appropriate error.
				return false;
			}

			const auto states_iterator = states_lookup_table.find(keys_iterator->second);

			if (states_iterator == states_lookup_table.end())
			{
				//TODO: throw appropriate error.
				return false;
			}

			return states_iterator->second;
		}

		vec2 InputManager::GetMousePosition() const
		{
			return mouse_position_;
		}
		void InputManager::SetMousePosition(const vec2 position)
		{
			mouse_position_ = position;
		}

		void InputManager::SetKeyUp(const int key)
		{
			const auto states_iterator = states_lookup_table.find(key);

			if (states_iterator == states_lookup_table.end()) return; //Key not in dictionary.

			states_iterator->second = false; //Set KeyDown boolean to false
		}

		void InputManager::SetKeyDown(const int key)
		{
			const auto states_iterator = states_lookup_table.find(key);

			if (states_iterator == states_lookup_table.end()) return; //Key not in dictionary.

			states_iterator->second = true; //Set KeyDown boolean to true
		}
	}
}