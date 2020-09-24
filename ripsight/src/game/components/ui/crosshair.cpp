#include <assert.h>
#include "crosshair.h"

void Crosshair::Birth()
{
	assert(GetOwner() != nullptr);
	m_OwnerTransform = GetOwner()->GetComponent<engine::Transform>();
}

void Crosshair::OnTick(float deltaTime)
{
	auto mousePosition = engine::Input::MouseState.GetMousePosition();
	m_OwnerTransform->GetPosition() = mousePosition;
}