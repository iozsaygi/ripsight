#include "weapon_info.h"

WeaponInfo::WeaponInfo()
{
	m_Damage = 0;
	m_FireRate = 0.0f;
}

WeaponInfo::WeaponInfo(int damage, float fireRate)
{
	m_Damage = damage;
	m_FireRate = fireRate;
}

int WeaponInfo::GetDamage()
{
	return m_Damage;
}

float WeaponInfo::GetFireRate()
{
	return m_FireRate;
}

void WeaponInfo::SetDamage(int damage)
{
	m_Damage = damage;
}

void WeaponInfo::SetFireRate(float fireRate)
{
	m_FireRate = fireRate;
}

WeaponInfo WeaponInfo::GetPistolInfo()
{
	WeaponInfo weaponInfo(1, 3.0f);
	return weaponInfo;
}