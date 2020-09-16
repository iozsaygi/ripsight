#ifndef WEAPON_INFO_H
#define WEAPON_INFO_H

struct WeaponInfo
{
public:
	WeaponInfo();
	WeaponInfo(int damage, float fireRate, float range);

	int GetDamage();
	float GetFireRate();
	float GetRange();
	void SetDamage(int damage);
	void SetFireRate(float fireRate);
	void SetRange(float range);

	static WeaponInfo GetPistolInfo();

private:
	int m_Damage;
	float m_FireRate;
	float m_Range;
};

#endif // !WEAPON_INFO_H