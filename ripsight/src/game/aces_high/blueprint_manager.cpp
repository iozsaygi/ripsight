#include <assert.h>
#include "game/components/entities/player/player_controller.h"
#include "game/components/entities/weapons/weapon_controller.h"
#include "game/components/ai/chase_controller.h"
#include "game/components/entities/spawners/enemy_spawner.h"
#include "blueprint_manager.h"

void BlueprintManager::CraftPlayer(engine::EngineEntry* engineEntry, engine::Actor* player)
{
	assert(player != nullptr);
	player->AddComponent<engine::Transform>(player, engine::Vector2D(300, 200), engine::Vector2D(48, 48));
	player->AddComponent<engine::SpriteRenderer>(player, engineEntry, "assets/imgs/entities/player/player.png");
	player->AddComponent<engine::BoxCollider2D>(player, engine::Vector2D(48, 48));
	player->AddComponent<PlayerController>(player, engineEntry, engine::Vector2D(3.0f, 3.0f));
	player->AddComponent<WeaponController>(player, WeaponInfo::GetPistolInfo());
}

void BlueprintManager::CraftZombie(engine::EngineEntry* engineEntry, engine::Actor* zombie)
{
	assert(zombie != nullptr);
	zombie->AddComponent<engine::Transform>(zombie, engine::Vector2D(360, 100), engine::Vector2D(40, 40));
	zombie->AddComponent<engine::SpriteRenderer>(zombie, engineEntry, "assets/imgs/entities/enemies/zombie.png");
	zombie->AddComponent<engine::BoxCollider2D>(zombie, engine::Vector2D(40, 40));
	zombie->AddComponent<ChaseController>(zombie, 0.5f);
}

void BlueprintManager::CraftEnemySpawner(engine::EngineEntry* engineEntry, engine::Actor* enemySpawner)
{
	assert(enemySpawner != nullptr);
	enemySpawner->AddComponent<EnemySpawner>(enemySpawner, engineEntry, 3.0f);
}