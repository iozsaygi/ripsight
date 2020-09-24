#include <iostream>
#include "game/components/common/damageable.h"
#include "game/components/ai/chase_controller.h"
#include "weapon_controller.h"

void WeaponController::Birth()
{
	// Yep, let's chase some pointers.
	m_StaticAudioPlayer = GetOwner()->GetOwnerWorld()->GetActorByName("Static Audio Player")->GetComponent<engine::AudioPlayer>();
	m_Player = GetOwner()->GetComponent<Player>();
	m_EnemySpawner = GetOwner()->GetOwnerWorld()->GetActorByName("Enemy Spawner")->GetComponent<EnemySpawner>();
}

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
	// If i am allowed to fire.
	if (m_CanFire)
	{
		auto audioPlayer = GetOwner()->GetComponent<engine::AudioPlayer>();
		if (audioPlayer != nullptr)
			audioPlayer->PlayOneShot(0, 40);

		// Fetch the transform component from our owner. (Maybe cache later?)
		auto transform = GetOwner()->GetComponent<engine::Transform>();
		if (transform != nullptr)
		{
			// Get the direction between player and mouse position.
			auto direction = engine::Input::MouseState.GetMousePosition().Subtract(transform->GetPosition());

			// Craft our ray.
			auto position = transform->GetPosition();
			auto center = position.Add(engine::Vector2D(transform->GetScale().GetX() / 2, transform->GetScale().GetY() / 2));
			engine::Ray ray(center, direction, m_WeaponInfo.GetRange());

			// Cast a ray using our fresh ray.
			engine::Actor* actor = Raycast2D(ray);

			if (actor != nullptr)
			{
				auto damageable = actor->GetComponent<Damageable>();
				if (damageable != nullptr)
				{
					if (!damageable->TakeDamage(m_WeaponInfo.GetDamage()))
					{
						std::cout << m_WeaponInfo.GetDamage() << " " << "damage dealt to zombie" << std::endl;
					}
					else
					{
						m_StaticAudioPlayer->PlayOneShot(1, 120);
						actor->GetOwnerWorld()->ScheduleActorForDestroy(actor);
						m_Player->AddScore(10);

						// Update the enemy spawner.
						int cScore = m_Player->GetScore();
						if (cScore % 50 == 0)
							m_EnemySpawner->SetSpawnRate(m_EnemySpawner->GetSpawnRate() - 0.5f);
					}
				}
			}
			else
			{
				std::cout << "Failed to fetch enemy data from raycast!" << std::endl;
			}
		}

		m_CanFire = false;
	}
}