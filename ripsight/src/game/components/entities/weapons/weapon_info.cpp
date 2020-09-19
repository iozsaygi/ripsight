#include "weapon_info.h"

WeaponInfo::WeaponInfo()
{
	m_Damage = 0;
	m_FireRate = 0.0f;
	m_Range = 0.0f;
}

WeaponInfo::WeaponInfo(int damage, float fireRate, float range)
{
	m_Damage = damage;
	m_FireRate = fireRate;
	m_Range = range;
}

int WeaponInfo::GetDamage()
{
	return m_Damage;
}

float WeaponInfo::GetFireRate()
{
	return m_FireRate;
}

float WeaponInfo::GetRange()
{
	return m_Range;
}

void WeaponInfo::SetDamage(int damage)
{
	m_Damage = damage;
}

void WeaponInfo::SetFireRate(float fireRate)
{
	m_FireRate = fireRate;
}

void WeaponInfo::SetRange(float range)
{
	m_Range = range;
}

WeaponInfo WeaponInfo::GetPistolInfo()
{
	WeaponInfo weaponInfo(100, 1.5f, 100.0f);
	return weaponInfo;
}