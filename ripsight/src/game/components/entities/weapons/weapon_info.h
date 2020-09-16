#ifndef WEAPON_INFO_H
#define WEAPON_INFO_H

struct WeaponInfo
{
public:
	WeaponInfo();
	WeaponInfo(int damage, float fireRate);

	int GetDamage();
	float GetFireRate();
	void SetDamage(int damage);
	void SetFireRate(float fireRate);

	static WeaponInfo GetPistolInfo();

private:
	int m_Damage;
	float m_FireRate;
};

#endif // !WEAPON_INFO_H