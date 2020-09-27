#include <assert.h>
#include "game/components/common/damageable.h"
#include "game/components/entities/player/player_controller.h"
#include "game/components/entities/weapons/weapon_controller.h"
#include "game/components/ai/chase_controller.h"
#include "game/components/entities/spawners/enemy_spawner.h"
#include "game/components/ui/button.h"
#include "game/components/ui/crosshair.h"
#include "game/components/entities/player/player.h"
#include "game/components/common/destroy_me.h"
#include "blueprint_manager.h"

void BlueprintManager::CraftBackground(engine::EngineEntry* engineEntry, engine::Actor* actor)
{
	assert(actor != nullptr);
	actor->AddComponent<engine::Transform>(actor, engine::Vector2D::Zero(), engine::Vector2D(800, 600));
	actor->AddComponent<engine::SpriteRenderer>(actor, engineEntry, "assets/imgs/env/sand_bg.png");
}

void BlueprintManager::CraftPlayer(engine::EngineEntry* engineEntry, engine::Actor* player)
{
	assert(player != nullptr);
	player->AddComponent<engine::Transform>(player, engine::Vector2D(400 - 24, 300 - 50), engine::Vector2D(48, 48));
	player->AddComponent<engine::SpriteRenderer>(player, engineEntry, "assets/imgs/entities/player/player.png");
	player->AddComponent<engine::BoxCollider2D>(player, engine::Vector2D(48, 48));
	player->AddComponent<Player>(player);
	player->AddComponent<PlayerController>(player, engineEntry, engine::Vector2D(3.0f, 3.0f));
	player->AddComponent<WeaponController>(engineEntry, player, WeaponInfo::GetPistolInfo());
	player->AddComponent<engine::AudioPlayer>(player, "assets/audio/wpn/pistol_fire.wav");
}

void BlueprintManager::CraftZombie(engine::EngineEntry* engineEntry, engine::Actor* zombie, engine::Vector2D initialPosition)
{
	assert(zombie != nullptr);
	zombie->AddComponent<engine::Transform>(zombie, initialPosition, engine::Vector2D(40, 40));
	zombie->AddComponent<engine::SpriteRenderer>(zombie, engineEntry, "assets/imgs/entities/enemies/zombie.png");
	zombie->AddComponent<engine::BoxCollider2D>(zombie, engine::Vector2D(40, 40));
	zombie->AddComponent<Damageable>(zombie, 100, 0);
	zombie->AddComponent<ChaseController>(zombie, 70.0f);
}

void BlueprintManager::CraftEnemySpawner(engine::EngineEntry* engineEntry, engine::Actor* enemySpawner)
{
	assert(enemySpawner != nullptr);
	enemySpawner->AddComponent<EnemySpawner>(enemySpawner, engineEntry, 1, 5, 3.0f);
}

void BlueprintManager::CraftStaticAudioPlayer(engine::Actor* staticAudioPlayer)
{
	assert(staticAudioPlayer != nullptr);
	staticAudioPlayer->AddComponent<engine::AudioPlayer>(staticAudioPlayer, "assets/audio/entities/zombie/death.wav");
}

void BlueprintManager::CraftButton(engine::EngineEntry* engineEntry, engine::Actor* actor)
{
	assert(actor != nullptr);
	actor->AddComponent<engine::Transform>(actor, engine::Vector2D(400 - 83, 500), engine::Vector2D(166, 72));
	actor->AddComponent<engine::SpriteRenderer>(actor, engineEntry, "assets/imgs/ui/button_revive.png");
	actor->AddComponent<Button>(actor);
}

void BlueprintManager::CraftPlayerDeathAudioPlayer(engine::Actor* actor)
{
	assert(actor != nullptr);
	actor->AddComponent<engine::AudioPlayer>(actor, "assets/audio/entities/player/death.wav");
}

void BlueprintManager::CraftCrosshair(engine::EngineEntry* engineEntry, engine::Actor* crosshair)
{
	assert(crosshair != nullptr);
	crosshair->AddComponent<engine::Transform>(crosshair, engine::Vector2D(400, 300), engine::Vector2D(64, 64));
	crosshair->AddComponent<engine::SpriteRenderer>(crosshair, engineEntry, "assets/imgs/ui/crosshair.png");
	crosshair->AddComponent<Crosshair>(crosshair);
}

void BlueprintManager::CraftText(engine::EngineEntry* engineEntry, engine::Actor* actor, engine::Vector2D position, engine::Vector2D scale,
	const std::string& path, const std::string& initialText, int fontSize, engine::Color color)
{
	assert(actor != nullptr);
	actor->AddComponent<engine::Transform>(actor, position, scale);
	actor->AddComponent<engine::Text>(actor, engineEntry, path, initialText, fontSize, color);
}

void BlueprintManager::CraftBloodSplash(engine::EngineEntry* engineEntry, engine::Actor* actor, engine::Vector2D position)
{
	assert(actor != nullptr);
	actor->AddComponent<engine::Transform>(actor, position, engine::Vector2D(64, 64));
	actor->AddComponent<engine::SpriteRenderer>(actor, engineEntry, "assets/imgs/effects/blood_splash.png");
	actor->AddComponent<DestroyMe>(actor, 3.0f);
}