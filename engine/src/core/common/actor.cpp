#include <assert.h>
#include "actor.h"
#include <SDL.h>

namespace engine
{
	Actor::Actor()
	{
		m_Components = std::vector<Component*>();
		m_ComponentMap = std::map<const std::type_info*, Component*>();
	}

	Actor::~Actor()
	{
		for (auto component : m_Components)
			delete component;

		m_Components.clear();
		m_ComponentMap.clear();
	}

	void Actor::AddComponent(Component* component)
	{
		assert(component != nullptr);
		m_Components.push_back(component);
		m_ComponentMap[&typeid(*component)] = component;
	}

	std::vector<Component*> Actor::GetComponents()
	{
		return m_Components;
	}
}