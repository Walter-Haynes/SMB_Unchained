#include "precomp.h"

#include <InputManager.h>

namespace Engine
{
	namespace Managers
	{
		void InputManager::RegisterNewKey(const int key, const std::string& name)
		{
			key_lookup_table_.insert({name, key});
			states_lookup_table_current_->insert({ key, false });
			states_lookup_table_last_->insert({ key, false });
		}

		bool InputManager::GetKey(const std::string& name)
		{
			const auto keys_iterator = key_lookup_table_.find(name);

			if (keys_iterator == key_lookup_table_.end())
			{
				//TODO: throw appropriate error.
				return false;
			}

			const auto states_iterator = states_lookup_table_current_->find(keys_iterator->second);

			if (states_iterator == states_lookup_table_current_->end())
			{
				//TODO: throw appropriate error.
				return false;
			}

			return states_iterator->second;
		}

		bool InputManager::GetKeyUp(const std::string& name)
		{
			const auto keys_iterator = key_lookup_table_.find(name);

			if (keys_iterator == key_lookup_table_.end())
			{
				//TODO: throw appropriate error.
				return false;
			}

			const bool key_current_state = GetState(states_lookup_table_current_, keys_iterator->second);
			const bool key_last_state    = GetState(states_lookup_table_last_, keys_iterator->second);

			//If the key's state switched to false in the current frame, return true.
			return (key_last_state == true && key_current_state == false);
		}

		bool InputManager::GetKeyDown(const std::string& name)
		{
			const auto keys_iterator = key_lookup_table_.find(name);

			if (keys_iterator == key_lookup_table_.end())
			{
				//TODO: throw appropriate error.
				return false;
			}

			const bool key_current_state = GetState(states_lookup_table_current_, keys_iterator->second);
			const bool key_last_state    = GetState(states_lookup_table_last_, keys_iterator->second);

			//If the key's state switched to true in the current frame, return true.
			return (key_last_state == false && key_current_state == true);
		}

		vec2 InputManager::GetMousePosition() const
		{
			return mouse_position_;
		}
		void InputManager::SetMousePosition(const vec2 position)
		{
			mouse_position_ = position;
		}

		void InputManager::SetKeyUp(const int key) const
		{
			SetState(states_lookup_table_last_, key, GetState(states_lookup_table_current_, key));
			SetState(states_lookup_table_current_, key, false);
		}

		void InputManager::SetKeyDown(const int key) const
		{
			SetState(states_lookup_table_last_, key, GetState(states_lookup_table_current_, key));
			SetState(states_lookup_table_current_, key, true);
		}
		
		bool InputManager::GetState(std::map<int, bool>* states_table, const int key)
		{
			const auto states_iterator = states_table->find(key);

			if (states_iterator == states_table->end())
			{
				//TODO: throw appropriate error.
				return false;
			}

			return states_iterator->second;
		}
		void InputManager::SetState(std::map<int, bool>* states_table, const int key, const bool value)
		{
			const auto states_iterator = states_table->find(key);

			if (states_iterator == states_table->end()) return; //Key not in dictionary.

			states_iterator->second = value; //Set KeyDown boolean to value
		}
	}
}