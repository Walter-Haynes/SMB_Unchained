#pragma once

namespace Engine
{
	namespace Utilities
	{
		template<typename T>
		///<summary> Manager class based on: https://gist.github.com/daniebker/2299755 </summary>
		class Manager
		{
			public:
				static T* Instance();
				static void Destroy();
	
			private:
				Manager(Manager const&)
				{ }
				//Manager& operator=(Manager const&) {};
	
			protected:
				static T* _instance;
	
				Manager()
				{
					_instance = static_cast<T*>(this);
				}

				~Manager() {  }
		};
	
		template<typename T>
		T* Manager<T>::_instance = nullptr;
	
		template<typename T>
		T* Manager<T>::Instance()
		{
			if (!_instance)
			{
				_instance = new T();
			}
	
			return _instance;
		}
	
		template<typename T>
		void Manager<T>::Destroy()
		{
			delete _instance;
			_instance = nullptr;
		}
	}
}