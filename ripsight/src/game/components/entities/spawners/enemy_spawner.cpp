#include <assert.h>
#include "enemy_spawner.h"

void EnemySpawner::Birth()
{
	assert(GetOwner() != nullptr);
	engine::Actor* zombie = new engine::Actor("Zombie");
	BlueprintManager::CraftZombie(m_EngineEntry, zombie);
	GetOwner()->GetOwnerWorld()->AddActorRuntime(zombie);
}