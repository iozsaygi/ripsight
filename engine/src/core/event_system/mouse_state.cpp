#include "mouse_state.h"

namespace engine
{
	bool MouseState::GetIsLeftMouseButtonDown()
	{
		return m_IsLeftButtonDown;
	}

	bool MouseState::GetIsRightMouseButtonDown()
	{
		return m_IsRightButtonDown;
	}

	void MouseState::SetIsLeftMouseButtonDown(bool status)
	{
		m_IsLeftButtonDown = status;
	}

	void MouseState::SetIsRightMouseButtonDown(bool status)
	{
		m_IsRightButtonDown = status;
	}
}