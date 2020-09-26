#include "engine.h"
#include "game/aces_high/blueprint_manager.h"

int main(int argc, char* argv[])
{
	engine::EngineEntry* engineEntry = new engine::EngineEntry("Ripsight - Alpha v0.1", 800, 600, 60);

	engine::World* world = new engine::World(engineEntry, true);
	engine::WorldManager::SetActiveWorld(world);

	engine::Actor* background = new engine::Actor("Background");
	BlueprintManager::CraftBackground(engineEntry, background);

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

	engine::Actor* playerScoreText = new engine::Actor("Player Score Text");
	BlueprintManager::CraftText(engineEntry, playerScoreText, engine::Vector2D(400, 5), engine::Vector2D(35, 35), 
		"assets/fonts/FiraCode/FiraCode-Regular.ttf", "0", 100, engine::Color(0, 0, 0));

	world->AddActor(background);
	world->AddActor(reviveButton);
	world->AddActor(enemySpawner);
	world->AddActor(player);
	world->AddActor(staticAudioPlayer);
	world->AddActor(playerDeathStaticAudioPlayer);
	world->AddActor(crosshair);
	world->AddActor(playerScoreText);

	world->Tick();

	delete world;
	delete engineEntry;

	return 0;
}