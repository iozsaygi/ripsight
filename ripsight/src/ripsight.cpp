#include "engine.h"

int main(int argc, char* argv[])
{
	// Initialize the engine by creating entry.
	engine::EngineEntry* engineEntry = new engine::EngineEntry("Ripsight", 800, 600, 60);

	// Create test world.
	engine::World* world = new engine::World(engineEntry, true);

	// Craft the player and add it to the test world.
	engine::Actor* player = new engine::Actor();
	engine::SpriteRenderer* spriteRenderer = new engine::SpriteRenderer("assets/imgs/entities/player/Player.png");
	player->AddComponent(spriteRenderer);
	world->AddActor(player);
	world->SubscribeToRenderQueue(spriteRenderer);

	// Start the world.
	world->Tick();

	// Clean up the trash.
	delete world;
	delete engineEntry;

	return 0;
}