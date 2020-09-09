#include "engine.h"
#include "game/components/entities/player/player_controller.h"

int main(int argc, char* argv[])
{
	// Initialize the engine by creating entry.
	engine::EngineEntry* engineEntry = new engine::EngineEntry("Ripsight", 800, 600, 60);

	// Create test world.
	engine::World* world = new engine::World(engineEntry, true);

	// Craft the player and add it to the test world.
	engine::Actor* player = new engine::Actor();
	engine::Transform* playerTransform = new engine::Transform(player, engine::Vector2D(300, 200), engine::Vector2D(64, 64));
	player->AddComponent(playerTransform);
	engine::SpriteRenderer* spriteRenderer = new engine::SpriteRenderer(player, "assets/imgs/entities/player/Player.png");
	PlayerController* playerController = new PlayerController(player, engine::Vector2D(3.0f, 3.0f));
	player->AddComponent(playerController);

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