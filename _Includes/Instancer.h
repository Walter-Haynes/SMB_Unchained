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
			static void DestroyAll();

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
			for(unsigned int i = 0; i < GetCount(); i++)
			{
				T* a = (*instances)[i];
				T* b = static_cast<T*>(this);
				
				if(a == b)
				{
					instances->RemoveAt(i);
				}
			}
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
		void Instancer<T>::DestroyAll()
		{
			delete instances;
		}
		
	}
}