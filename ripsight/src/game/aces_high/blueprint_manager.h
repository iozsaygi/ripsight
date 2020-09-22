#ifndef BLUEPRINT_MANAGER_H
#define BLUEPRINT_MANAGER_H

#include "engine.h"

class BlueprintManager
{
public:
	static void CraftPlayer(engine::EngineEntry* engineEntry, engine::Actor* player);
	static void CraftZombie(engine::EngineEntry* engineEntry, engine::Actor* zombie, engine::Vector2D initialPosition);
	static void CraftEnemySpawner(engine::EngineEntry* engineEntry, engine::Actor* enemySpawner);
	static void CraftStaticAudioPlayer(engine::Actor* staticAudioPlayer);
	static void CraftButton(engine::EngineEntry* engineEntry, engine::Actor* actor);
	static void CraftPlayerDeathAudioPlayer(engine::Actor* actor);
};

#endif // !BLUEPRINT_MANAGER_H