#include "engine.h"
#include "game/components/entities/player/player_controller.h"
#include "game/components/entities/weapons/weapon_info.h"
#include "game/components/entities/weapons/weapon_controller.h"
#include "game/components/ai/chase_controller.h"

int main(int argc, char* argv[])
{
	// Initialize the engine by creating entry.
	engine::EngineEntry* engineEntry = new engine::EngineEntry("Ripsight", 800, 600, 60);

	// Create test world.
	engine::World* world = new engine::World(engineEntry, true);

	// Craft the player.
	engine::Actor* player = new engine::Actor("Player");
	player->AddComponent<engine::Transform>(player, engine::Vector2D(300, 200), engine::Vector2D(48, 48));
	player->AddComponent<engine::SpriteRenderer>(player, engineEntry, "assets/imgs/entities/player/player.png");
	player->AddComponent<PlayerController>(player, engineEntry, engine::Vector2D(3.0f, 3.0f));
	player->AddComponent<WeaponController>(player, WeaponInfo::GetPistolInfo());

	// Craft the zombie.
	engine::Actor* zombie = new engine::Actor("Zombie");
	zombie->AddComponent<engine::Transform>(zombie, engine::Vector2D(360, 100), engine::Vector2D(40, 40));
	zombie->AddComponent<engine::SpriteRenderer>(zombie, engineEntry, "assets/imgs/entities/enemies/zombie.png");
	zombie->AddComponent<ChaseController>(zombie, 0.5f);

	world->AddActor(player);
	world->AddActor(zombie);

	// Start the world.
	world->Tick();

	// Clean up the trash.
	delete world;
	delete engineEntry;

	return 0;
}