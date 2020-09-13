#ifndef ENEMY_SPAWNER_H
#define ENEMY_SPAWNER_H

#include "engine.h"
#include "game/aces_high/blueprint_manager.h"

class EnemySpawner : public engine::Component
{
public:
	EnemySpawner(engine::Actor* owner, engine::EngineEntry* engineEntry) : engine::Component(owner)
	{
		m_EngineEntry = engineEntry;
		m_SpawnRate = 3.0f;
	}

	EnemySpawner(engine::Actor* owner, engine::EngineEntry* engineEntry, float spawnRate) : engine::Component(owner)
	{
		m_EngineEntry = engineEntry;
		m_SpawnRate = spawnRate;
	}

	void Birth() override;

private:
	engine::EngineEntry* m_EngineEntry = nullptr;
	float m_SpawnRate;
};

#endif // !ENEMY_SPAWNER_H