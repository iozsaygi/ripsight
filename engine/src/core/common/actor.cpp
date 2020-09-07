#include <assert.h>
#include "actor.h"

namespace engine
{
	Actor::Actor()
	{
		m_Components = std::vector<Component*>();
	}

	Actor::~Actor()
	{
		for (auto component : m_Components)
			delete component;

		m_Components.clear();
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