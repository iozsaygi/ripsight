#include "engine.h"
#include "game/aces_high/blueprint_manager.h"
#include "game/components/ai/chase_controller.h"

int main(int argc, char* argv[])
{
	engine::EngineEntry* engineEntry = new engine::EngineEntry("Ripsight", 800, 600, 60);

	engine::World* world = new engine::World(engineEntry, true);

	engine::Actor* player = new engine::Actor("Player");
	BlueprintManager::CraftPlayer(engineEntry, player);

	engine::Actor* zombie = new engine::Actor("Zombie");
	BlueprintManager::CraftZombie(engineEntry, zombie);

	world->AddActor(player);
	world->AddActor(zombie);

	world->Tick();

	delete world;
	delete engineEntry;

	return 0;
}