#include "weapon_controller.h"

void WeaponController::OnTick(float deltaTime)
{
	m_FireTimer += deltaTime;
	if (m_FireTimer >= m_WeaponInfo.GetFireRate())
	{
		m_FireTimer = 0.0f;
		m_CanFire = true;
	}
}

void WeaponController::Fire()
{
	if (m_CanFire)
	{
		SDL_Log("Fire!");
		m_CanFire = false;
	}
}