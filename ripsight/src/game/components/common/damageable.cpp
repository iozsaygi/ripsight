#include "damageable.h"

bool Damageable::TakeDamage(int incomingDamage)
{
	assert(incomingDamage > 0);
	m_CurrentHealth -= incomingDamage;

	if (m_CurrentHealth <= m_MinimumHealth)
	{
		m_CurrentHealth = m_MinimumHealth;
		return true;
	}
	else
	{
		return false;
	}
}