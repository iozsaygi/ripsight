#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include "keycode.h"
#include "mouse_state.h"

namespace engine
{
	class Input
	{
	public:
		static KeyCode WKeyCode;
		static KeyCode AKeyCode;
		static KeyCode SKeyCode;
		static KeyCode DKeyCode;
		static MouseState MouseState;

		// Do not call this function from client side.
		static void UpdateKeyStates(SDL_Event& event);
	};
}

#endif // !INPUT_H