#include "button.h"

void Button::Birth()
{
	m_Transform = GetOwner()->GetComponent<engine::Transform>();
}

void Button::OnTick(float deltaTime)
{
	if (engine::Input::MouseState.GetIsLeftMouseButtonDown() && !m_IsTriggered)
	{
		auto mousePosition = engine::Input::MouseState.GetMousePosition();

		if (m_Transform->IsPositionInsideMe(mousePosition))
		{
			// Add an event system instead of hard coding events like that.
			PlayerController::Revive();
			m_IsTriggered = true;
		}
	}

	if (!engine::Input::MouseState.GetIsLeftMouseButtonDown() && m_IsTriggered)
		m_IsTriggered = false;
}