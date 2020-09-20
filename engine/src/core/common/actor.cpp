#include <assert.h>
#include "actor.h"
#include <SDL.h>

namespace engine
{
	Actor::Actor(const std::string& name)
	{
		m_Components = std::vector<Component*>();
		m_ComponentMap = std::map<const std::type_info*, Component*>();
		m_Name = name;
		m_IsActive = true;
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

	World* Actor::GetOwnerWorld()
	{
		return m_OwnerWorld;
	}

	void Actor::SetOwnerWorld(World* world)
	{
		assert(world != nullptr);
		m_OwnerWorld = world;
	}

	std::string& Actor::GetName()
	{
		return m_Name;
	}

	bool& Actor::GetIsActive()
	{
		return m_IsActive;
	}

	void Actor::SetIsActive(bool isActive)
	{
		m_IsActive = isActive;
	}
}