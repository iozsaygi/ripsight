#ifndef ENEMY_SPAWNER_H
#define ENEMY_SPAWNER_H

#include "engine.h"
#include "game/aces_high/blueprint_manager.h"

class EnemySpawner : public engine::Component
{
public:
	EnemySpawner(engine::Actor* owner, engine::EngineEntry* engineEntry, int minSpawnCount, int maxSpawnCount) : engine::Component(owner)
	{
		m_EngineEntry = engineEntry;
		m_SpawnRate = 3.0f;
		m_MinSpawnCount = minSpawnCount;
		m_MaxSpawnCount = maxSpawnCount;
	}

	EnemySpawner(engine::Actor* owner, engine::EngineEntry* engineEntry, int minSpawnCount, int maxSpawnCount, float spawnRate) : engine::Component(owner)
	{
		m_EngineEntry = engineEntry;
		m_SpawnRate = spawnRate;
		m_MinSpawnCount = minSpawnCount;
		m_MaxSpawnCount = maxSpawnCount;
	}

	void Birth() override;
	void OnTick(float deltaTime) override;
	void Spawn();

	float GetSpawnRate();
	void SetSpawnRate(float spawnRate);

private:
	engine::EngineEntry* m_EngineEntry = nullptr;
	engine::Actor* m_PlayerReference = nullptr;
	float m_SpawnRate;
	float m_SpawnTimer = 0.0f;
	int m_MinSpawnCount = 0;
	int m_MaxSpawnCount = 0;
};

#endif // !ENEMY_SPAWNER_H