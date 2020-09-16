#ifndef WORLD_MANAGER_H
#define WORLD_MANAGER_H

#include "world.h"

namespace engine
{
	class WorldManager
	{
	public:
		static World* GetActiveWorld();
		static void SetActiveWorld(World* world);

	private:
		static World* m_CurrentActiveWorld;
	};
}

#endif // !WORLD_MANAGER_H