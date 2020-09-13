#ifndef BLUEPRINT_MANAGER_H
#define BLUEPRINT_MANAGER_H

#include "engine.h"

class BlueprintManager
{
public:
	static void CraftPlayer(engine::EngineEntry* engineEntry, engine::Actor* player);
	static void CraftZombie(engine::EngineEntry* engineEntry, engine::Actor* zombie);
};

#endif // !BLUEPRINT_MANAGER_H