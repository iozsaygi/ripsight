#ifndef MOUSE_STATE_H
#define MOUSE_STATE_H

namespace engine
{
	class MouseState
	{
	public:
		bool GetIsLeftMouseButtonDown();
		bool GetIsRightMouseButtonDown();
		void SetIsLeftMouseButtonDown(bool status);
		void SetIsRightMouseButtonDown(bool status);

	private:
		bool m_IsLeftButtonDown = false;
		bool m_IsRightButtonDown = false;
	};
}

#endif // !MOUSE_STATE_H