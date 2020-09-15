#include <assert.h>
#include <math.h>
#include "player_controller.h"

void PlayerController::Birth()
{
	assert(GetOwner() != nullptr);
	m_OwnerTransform = GetOwner()->GetComponent<engine::Transform>();
	m_OwnerSpriteRenderer = GetOwner()->GetComponent<engine::SpriteRenderer>();
	m_WeaponController = GetOwner()->GetComponent<WeaponController>();
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
	GetOwner()->GetIsActive() = false;
}