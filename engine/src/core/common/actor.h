#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include "component.h"

namespace engine
{
	// Actor is container of components.
	class Actor
	{
	public:
		Actor();
		~Actor();

		// Adds given component to the actor.
		void AddComponent(Component* component);

		// Returns the all components of actor.
		std::vector<Component*> GetComponents();

	private:
		std::vector<Component*> m_Components;
	};
}

#endif // !ACTOR_H