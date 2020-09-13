#include <assert.h>
#include "chase_controller.h"

void ChaseController::Birth()
{
	assert(GetOwner() != nullptr);
	m_SpriteRenderer = GetOwner()->GetComponent<engine::SpriteRenderer>();
	// Holy moly...
	m_TargetTransform = GetOwner()->GetOwnerWorld()->GetActorByName("Player")->GetComponent<engine::Transform>();
	m_OwnerTransform = GetOwner()->GetComponent<engine::Transform>();
}

void ChaseController::OnTick(float deltaTime)
{
	// Only chase if my target is active.
	if (m_TargetTransform->GetOwner()->GetIsActive())
	{
		auto deltaX = m_OwnerTransform->GetPosition().GetX() - m_TargetTransform->GetPosition().GetX();
		auto deltaY = m_OwnerTransform->GetPosition().GetY() - m_TargetTransform->GetPosition().GetY();
		auto degreeInRad = atan2(deltaY, deltaX);
		auto degreeInAngle = (degreeInRad * 180.0000) / 3.1416;
		m_SpriteRenderer->UpdateRenderAngle(degreeInAngle + 180.0f);

		engine::Vector2D targetPosition = m_TargetTransform->GetPosition();
		engine::Vector2D direction = targetPosition - m_OwnerTransform->GetPosition();
		m_OwnerTransform->GetPosition() += engine::Vector2D(direction.GetX() * m_ChaseSpeed * deltaTime, direction.GetY() * m_ChaseSpeed * deltaTime);
	}
}