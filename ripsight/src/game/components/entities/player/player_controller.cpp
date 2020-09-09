#include <assert.h>
#include "player_controller.h"

void PlayerController::Birth()
{
	assert(GetOwner() != nullptr);
	m_OwnerTransform = GetOwner()->GetComponent<engine::Transform>();
}

void PlayerController::OnTick(float deltaTime)
{
	if (engine::Input::WKeyCode.GetIsKeyDown())
	{
		m_OwnerTransform->GetPosition().Subtract(engine::Vector2D(0.0f, m_Velocity.GetY() + deltaTime));
	}

	if (engine::Input::AKeyCode.GetIsKeyDown())
	{
		m_OwnerTransform->GetPosition().Subtract(engine::Vector2D(m_Velocity.GetX() + deltaTime, 0.0f));
	}

	if (engine::Input::SKeyCode.GetIsKeyDown())
	{
		m_OwnerTransform->GetPosition().Add(engine::Vector2D(0.0f, m_Velocity.GetY() + deltaTime));
	}

	if (engine::Input::DKeyCode.GetIsKeyDown())
	{
		m_OwnerTransform->GetPosition().Add(engine::Vector2D(m_Velocity.GetX() + deltaTime, 0.0f));
	}
}