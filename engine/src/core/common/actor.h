#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <vector>
#include <typeinfo>
#include <map>
#include "component.h"

namespace engine
{
	class World;

	// Actor is container of components.
	class Actor
	{
	public:
		Actor(const std::string& name);
		~Actor();

		// Adds given component to the actor.
		void AddComponent(Component* component);

		template <typename T, typename... TArgs>
		T& AddComponent(TArgs&&... args)
		{
			T* newComponent(new T(std::forward<TArgs>(args)...));
			newComponent->SetOwner(this);
			m_Components.push_back(newComponent);
			m_ComponentMap[&typeid(*newComponent)] = newComponent;
			return *newComponent;
		}

		// Returns the all components of actor.
		std::vector<Component*> GetComponents();

		template <typename T>
		T* GetComponent()
		{
			return static_cast<T*>(m_ComponentMap[&typeid(T)]);
		}

		World* GetOwnerWorld();
		void SetOwnerWorld(World* world);
		std::string& GetName();
		bool& GetIsActive();
		void SetIsActive(bool isActive);

	private:
		std::string m_Name;
		bool m_IsActive = true;
		std::vector<Component*> m_Components;
		std::map<const std::type_info*, Component*> m_ComponentMap;
		World* m_OwnerWorld = nullptr;
	};
}

#endif // !ACTOR_H