#pragma once

#include <List.h>

namespace Engine
{
	namespace Components
	{
		class Component
		{
			public:
				Component() = default;

				Component(Component* parent) : parent_(parent)
				{ }

				virtual ~Component() 
				{
					//delete parent_;
				}

				Component* GetParent() const
				{
					return parent_;
				}
				void SetParent(Component* parent)
				{
					//TODO: Maybe remove itself from current parent first? (if there is one)
					
					this->parent_ = parent;
				}


				void AddComponent(Component* component)
				{
					component->SetParent(this);

					components_.Add(component);
				}

				template<class T>
				T* GetComponent()
				{
					T* component;

					for (unsigned int i = 0; i < components_.Count(); i++)
					{
						if ((component = dynamic_cast<T*>(components_[i])))
						{
							return component;
						}
					}

					return nullptr;
				}

			private:
				Component* parent_ = nullptr;
				Types::List<Component*> components_ = *new Types::List<Component*>();
		};
	}
}