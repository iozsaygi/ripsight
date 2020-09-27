#ifndef WEAPON_CONTROLLER_H
#define WEAPON_CONTROLLER_H

#include "engine.h"
#include "game/components/entities/player/player.h"
#include "game/components/entities/spawners/enemy_spawner.h"
#include "weapon_info.h"

class WeaponController : public engine::Component
{
public:
	inline WeaponController(engine::EngineEntry* engineEntry, engine::Actor* owner, const WeaponInfo& weaponInfo) : Component(owner)
	{
		m_EngineEntry = engineEntry;

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
	Player* m_Player = nullptr;
	EnemySpawner* m_EnemySpawner = nullptr;
	engine::Text* m_PlayerScoreText = nullptr;
	engine::EngineEntry* m_EngineEntry = nullptr;
};

#endif // !WEAPON_CONTROLLER_H