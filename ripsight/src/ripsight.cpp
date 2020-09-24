#include "engine.h"
#include "game/aces_high/blueprint_manager.h"

int main(int argc, char* argv[])
{
	engine::EngineEntry* engineEntry = new engine::EngineEntry("Ripsight - Alpha v0.1", 800, 600, 60);

	engine::World* world = new engine::World(engineEntry, true);
	engine::WorldManager::SetActiveWorld(world);

	engine::Actor* player = new engine::Actor("Player");
	BlueprintManager::CraftPlayer(engineEntry, player);

	engine::Actor* reviveButton = new engine::Actor("Revive Button");
	BlueprintManager::CraftButton(engineEntry, reviveButton);

	engine::Actor* enemySpawner = new engine::Actor("Enemy Spawner");
	BlueprintManager::CraftEnemySpawner(engineEntry, enemySpawner);

	engine::Actor* staticAudioPlayer = new engine::Actor("Static Audio Player");
	BlueprintManager::CraftStaticAudioPlayer(staticAudioPlayer);

	engine::Actor* playerDeathStaticAudioPlayer = new engine::Actor("Player Death Static Audio Player");
	BlueprintManager::CraftPlayerDeathAudioPlayer(playerDeathStaticAudioPlayer);

	engine::Actor* crosshair = new engine::Actor("Crosshair");
	BlueprintManager::CraftCrosshair(engineEntry, crosshair);

	world->AddActor( reviveButton );
	world->AddActor( player );
	world->AddActor( enemySpawner );
	world->AddActor( staticAudioPlayer );
	world->AddActor( playerDeathStaticAudioPlayer );
	world->AddActor( crosshair );

	world->Tick();

	delete world;
	delete engineEntry;

	return 0;
}