#ifndef ENEMY_SPAWNER_H
#define ENEMY_SPAWNER_H

#include "engine.h"

class EnemySpawner : public engine::Component
{
public:
	EnemySpawner(engine::Actor* owner) : engine::Component(owner)
	{
		m_SpawnRate = 3.0f;
	}

	EnemySpawner(engine::Actor* owner, float spawnRate) : engine::Component(owner)
	{
		m_SpawnRate = spawnRate;
	}

private:
	float m_SpawnRate;
};

#endif // !ENEMY_SPAWNER_H