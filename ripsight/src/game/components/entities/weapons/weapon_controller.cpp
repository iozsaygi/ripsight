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
	// If i am allowed to fire.
	if (m_CanFire)
	{
		// Fetch the transform component from our owner. (Maybe cache later?)
		auto transform = GetOwner()->GetComponent<engine::Transform>();
		if (transform != nullptr)
		{
			// Get the direction between player and mouse position.
			auto direction = engine::Input::MouseState.GetMousePosition().Subtract(transform->GetPosition());

			// Craft our ray.
			engine::Ray ray(transform->GetPosition(), direction, m_WeaponInfo.GetRange());

			// Cast a ray using our fresh ray.
			engine::Actor* actor = Raycast2D(ray);

			if (actor != nullptr)
			{
				actor->GetIsActive() = false;
				SDL_Log("Killed a zombie!");
			}
			else
			{
				SDL_Log("I didn't hit anything!");
			}
		}

		m_CanFire = false;
	}
}