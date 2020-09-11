#include "engine.h"
#include "game/components/entities/player/player_controller.h"
#include "game/components/entities/weapons/weapon_info.h"
#include "game/components/entities/weapons/weapon_controller.h"

int main(int argc, char* argv[])
{
	// Initialize the engine by creating entry.
	engine::EngineEntry* engineEntry = new engine::EngineEntry("Ripsight", 800, 600, 60);

	// Create test world.
	engine::World* world = new engine::World(engineEntry, true);

	// Craft the background.
	engine::Actor* background = new engine::Actor();
	engine::Transform* backgroundTransform = new engine::Transform(background, engine::Vector2D::Zero(), engine::Vector2D(800, 600));
	background->AddComponent(backgroundTransform);
	engine::SpriteRenderer* backgroundRenderer = new engine::SpriteRenderer(background, engineEntry, "assets/imgs/entities/background/background.png");
	background->AddComponent(backgroundRenderer);
	world->AddActor(background);

	// Craft the player and add it to the test world.
	engine::Actor* player = new engine::Actor();
	engine::Transform* playerTransform = new engine::Transform(player, engine::Vector2D(300, 200), engine::Vector2D(48, 48));
	player->AddComponent(playerTransform);
	engine::SpriteRenderer* spriteRenderer = new engine::SpriteRenderer(player, engineEntry, "assets/imgs/entities/player/player.png");
	PlayerController* playerController = new PlayerController(player, engineEntry, engine::Vector2D(3.0f, 3.0f));
	player->AddComponent(playerController);
	WeaponController* weaponController = new WeaponController(player, WeaponInfo::GetPistolInfo());
	player->AddComponent(weaponController);

	player->AddComponent(spriteRenderer);
	world->AddActor(player);

	// Start the world.
	world->Tick();

	// Clean up the trash.
	delete world;
	delete engineEntry;

	return 0;
}