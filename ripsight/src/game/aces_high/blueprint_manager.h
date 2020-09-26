#ifndef BLUEPRINT_MANAGER_H
#define BLUEPRINT_MANAGER_H

#include <string>
#include "engine.h"

class BlueprintManager
{
public:
	static void CraftBackground(engine::EngineEntry* engineEntry, engine::Actor* actor);
	static void CraftPlayer(engine::EngineEntry* engineEntry, engine::Actor* player);
	static void CraftZombie(engine::EngineEntry* engineEntry, engine::Actor* zombie, engine::Vector2D initialPosition);
	static void CraftEnemySpawner(engine::EngineEntry* engineEntry, engine::Actor* enemySpawner);
	static void CraftStaticAudioPlayer(engine::Actor* staticAudioPlayer);
	static void CraftButton(engine::EngineEntry* engineEntry, engine::Actor* actor);
	static void CraftPlayerDeathAudioPlayer(engine::Actor* actor);
	static void CraftCrosshair(engine::EngineEntry* engineEntry, engine::Actor* crosshair);

	static void CraftText(engine::EngineEntry* engineEntry, engine::Actor* actor, engine::Vector2D position, engine::Vector2D scale, 
		const std::string& path, const std::string& initialText, int fontSize, engine::Color color);
};

#endif // !BLUEPRINT_MANAGER_H