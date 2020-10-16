#pragma once

#include <List.h>
using Engine::Types::List;

namespace Engine
{
	namespace Utilities
	{
		///<summary> Class that statically tracks all instances of itself. </summary>
		template<typename T>
		class Instancer
		{
		public:
			static T* GetInstance(unsigned int index);
			static void Destroy();

			static List<T*>* instances;

			static unsigned int GetCount();

		protected:
			Instancer();
			~Instancer();
		};

		template<typename T>
		List<T*>* Instancer<T>::instances = new List<T*>();


		template<typename T>
		unsigned int Instancer<T>::GetCount()
		{
			return instances->Count();
		}

		template<typename T>
		Instancer<T>::Instancer()
		{
			this->instances->Add(static_cast<T*>(this));
		}
		template<typename T>
		Instancer<T>::~Instancer()
		{
			this->Destroy();
		}


		template<typename T>
		T* Instancer<T>::GetInstance(unsigned int index)
		{
			if(!instances)
			{
				instances = new List<T*>;
			}
			
			return (*instances)[index];
		}

		template<typename T>
		void Instancer<T>::Destroy()
		{
			delete instances;
		}
		
	}
}