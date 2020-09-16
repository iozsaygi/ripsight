#include <assert.h>
#include "world_manager.h"

namespace engine
{
	World* WorldManager::m_CurrentActiveWorld = nullptr;

	World* WorldManager::GetActiveWorld()
	{
		return m_CurrentActiveWorld;
	}

	void WorldManager::SetActiveWorld(World* world)
	{
		assert(world != nullptr);
		m_CurrentActiveWorld = world;
	}
}