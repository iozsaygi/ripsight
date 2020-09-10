#ifndef MOUSE_STATE_H
#define MOUSE_STATE_H

#include <SDL.h>
#include "math/vector2D.h"

namespace engine
{
	class MouseState
	{
	public:
		bool GetIsLeftMouseButtonDown();
		bool GetIsRightMouseButtonDown();
		void SetIsLeftMouseButtonDown(bool status);
		void SetIsRightMouseButtonDown(bool status);
		Vector2D GetMousePosition();

	private:
		bool m_IsLeftButtonDown = false;
		bool m_IsRightButtonDown = false;
	};
}

#endif // !MOUSE_STATE_H