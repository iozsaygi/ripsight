#include <iostream>
#include "button.h"

void Button::Birth()
{
	m_Transform = GetOwner()->GetComponent<engine::Transform>();
}

void Button::OnTick(float deltaTime)
{
	if (engine::Input::MouseState.GetIsLeftMouseButtonDown())
	{
		auto mousePosition = engine::Input::MouseState.GetMousePosition();

		if (m_Transform->IsPositionInsideMe(mousePosition))
			std::cout << "Clicked on me!" << std::endl;
	}
}