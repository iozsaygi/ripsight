#include <assert.h>
#include "actor.h"

namespace engine
{
	Actor::Actor()
	{
		m_Components = std::vector<Component*>();
	}

	void Actor::AddComponent(Component* component)
	{
		assert(component != nullptr);
		m_Components.push_back(component);
	}

	std::vector<Component*> Actor::GetComponents()
	{
		return m_Components;
	}
}