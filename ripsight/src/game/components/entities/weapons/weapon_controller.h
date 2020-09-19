#ifndef WEAPON_CONTROLLER_H
#define WEAPON_CONTROLLER_H

#include "engine.h"
#include "weapon_info.h"

class WeaponController : public engine::Component
{
public:
	WeaponController(engine::Actor* owner, const WeaponInfo& weaponInfo) : Component(owner)
	{
		m_WeaponInfo.SetDamage(weaponInfo.GetPistolInfo().GetDamage());
		m_WeaponInfo.SetFireRate(weaponInfo.GetPistolInfo().GetFireRate());
		m_WeaponInfo.SetRange(weaponInfo.GetPistolInfo().GetRange());
	}

	void Birth() override;
	void OnTick(float deltaTime) override;
	void Fire();

private:
	float m_FireTimer = 0.0f;
	bool m_CanFire = true;
	WeaponInfo m_WeaponInfo;
	engine::AudioPlayer* m_StaticAudioPlayer = nullptr;
};

#endif // !WEAPON_CONTROLLER_H