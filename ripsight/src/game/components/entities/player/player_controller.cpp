#include <assert.h>
#include <math.h>
#include <iostream>
#include "game/components/ui/button.h"
#include "game/components/ai/chase_controller.h"
#include "game/components/entities/spawners/enemy_spawner.h"
#include "player_controller.h"

void PlayerController::Birth()
{
	assert(GetOwner() != nullptr);
	m_OwnerTransform = GetOwner()->GetComponent<engine::Transform>();
	m_OwnerSpriteRenderer = GetOwner()->GetComponent<engine::SpriteRenderer>();
	m_WeaponController = GetOwner()->GetComponent<WeaponController>();
	m_ReviveButton = GetOwner()->GetOwnerWorld()->GetActorByName("Revive Button");
	m_ReviveButton->SetIsActive(false);
}

void PlayerController::OnTick(float deltaTime)
{
	auto deltaX = m_OwnerTransform->GetPosition().GetX() - engine::Input::MouseState.GetMousePosition().GetX();
	auto deltaY = m_OwnerTransform->GetPosition().GetY() - engine::Input::MouseState.GetMousePosition().GetY();
	auto degreeInRad = atan2(deltaY, deltaX);
	auto degreeInAngle = (degreeInRad * 180.0000) / 3.1416;
	m_OwnerSpriteRenderer->UpdateRenderAngle(degreeInAngle + 180.0);

	if (engine::Input::WKeyCode.GetIsKeyDown())
	{
		auto transformPosition = m_OwnerTransform->GetPosition();
		auto calculatedMovement = transformPosition.Subtract(engine::Vector2D(0.0f, m_Velocity.GetY() + deltaTime));
		if (calculatedMovement.GetY() >= 0)
			m_OwnerTransform->GetPosition().Subtract(engine::Vector2D(0.0f, m_Velocity.GetY() + deltaTime));
	}

	if (engine::Input::AKeyCode.GetIsKeyDown())
	{
		auto transformPosition = m_OwnerTransform->GetPosition();
		auto calculatedMovement = transformPosition.Subtract(engine::Vector2D(m_Velocity.GetX() + deltaTime, 0.0f));
		if (calculatedMovement.GetX() >= 0)
			m_OwnerTransform->GetPosition().Subtract(engine::Vector2D(m_Velocity.GetX() + deltaTime, 0.0f));
	}

	if (engine::Input::SKeyCode.GetIsKeyDown())
	{
		auto transformPosition = m_OwnerTransform->GetPosition();
		auto calculatedMovement = transformPosition.Add(engine::Vector2D(0.0f, m_Velocity.GetY() + deltaTime));
		if (calculatedMovement.GetY() + m_OwnerTransform->GetScale().GetY() <= m_EngineEntry->GetWindowHeight())
			m_OwnerTransform->GetPosition().Add(engine::Vector2D(0.0f, m_Velocity.GetY() + deltaTime));
	}

	if (engine::Input::DKeyCode.GetIsKeyDown())
	{
		auto transformPosition = m_OwnerTransform->GetPosition();
		auto calculatedMovement = transformPosition.Add(engine::Vector2D(m_Velocity.GetX() + deltaTime, 0.0f));
		if (calculatedMovement.GetX() + m_OwnerTransform->GetScale().GetX() <= m_EngineEntry->GetWindowWidth())
			m_OwnerTransform->GetPosition().Add(engine::Vector2D(m_Velocity.GetX() + deltaTime, 0.0f));
	}

	if (engine::Input::MouseState.GetIsLeftMouseButtonDown())
		m_WeaponController->Fire();
}

void PlayerController::OnCollision(engine::Actor* other)
{
	// This is ugly game code?
	auto pdsap = engine::WorldManager::GetActiveWorld()->GetActorByName("Player Death Static Audio Player");
	pdsap->GetComponent<engine::AudioPlayer>()->PlayOneShot(3, 120);

	m_ReviveButton->SetIsActive(true);
	GetOwner()->GetIsActive() = false;
}

void PlayerController::Revive()
{
	auto activeWorld = engine::WorldManager::GetActiveWorld();
	if (activeWorld != nullptr)
	{
		auto player = activeWorld->GetActorByName("Player");
		if (player != nullptr)
		{
			// Clear all the alive zombies before activating player.
			for (auto collider : activeWorld->GetCollidersInWorld())
			{
				auto ai = collider->GetOwner()->GetComponent<ChaseController>();
				if (ai != nullptr)
					activeWorld->ScheduleActorForDestroy(ai->GetOwner());
			}

			auto es = activeWorld->GetActorByName("Enemy Spawner")->GetComponent<EnemySpawner>();
			if (es != nullptr)
				es->SetSpawnRate(3.0f);

			player->GetComponent<Player>()->SetScore(0);
			auto st = activeWorld->GetActorByName("Player Score Text")->GetComponent<engine::Text>();
			st->UpdateText("0");

			player->SetIsActive(true);
			player->GetComponent<engine::Transform>()->GetPosition() = engine::Vector2D(400 - 24, 300 - 50);
			auto reviveButton = activeWorld->GetActorByName("Revive Button");
			if (reviveButton != nullptr)
				reviveButton->SetIsActive(false);
		}
	}
}