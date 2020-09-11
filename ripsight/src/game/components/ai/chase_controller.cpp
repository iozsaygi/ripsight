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
	auto deltaX = m_OwnerTransform->GetPosition().GetX() - m_TargetTransform->GetPosition().GetX();
	auto deltaY = m_OwnerTransform->GetPosition().GetY() - m_TargetTransform->GetPosition().GetY();
	auto degreeInRad = atan2(deltaY, deltaX);
	auto degreeInAngle = (degreeInRad * 180.0000) / 3.1416;
	m_SpriteRenderer->UpdateRenderAngle(degreeInAngle + 180.0f);
}