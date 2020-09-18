#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

#include <assert.h>
#include "engine.h"

class Damageable : public engine::Component
{
public:
	Damageable(engine::Actor* owner) : engine::Component(owner)
	{
		m_MaximumHealth = 0;
		m_CurrentHealth = 0;
		m_MinimumHealth = 0;
	}

	Damageable(engine::Actor* owner, int maximumHealth, int minimumHealth) : engine::Component(owner)
	{
		assert(maximumHealth > 0);
		assert(minimumHealth >= 0);
		assert(maximumHealth > minimumHealth);
		m_MaximumHealth = maximumHealth;
		m_CurrentHealth = maximumHealth;
		m_MinimumHealth = minimumHealth;
	}

	bool TakeDamage(int incomingDamage);

private:
	int m_MaximumHealth;
	int m_CurrentHealth;
	int m_MinimumHealth;
};

#endif // !DAMAGEABLE_H