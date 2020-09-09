#include "input.h"

namespace engine
{
	KeyCode Input::WKeyCode;
	KeyCode Input::AKeyCode;
	KeyCode Input::SKeyCode;
	KeyCode Input::DKeyCode;
	MouseState Input::MouseState;

	void Input::UpdateKeyStates(SDL_Event& event)
	{
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				WKeyCode.UpdateIsKeyDown(true);
				break;

			case SDLK_a:
				AKeyCode.UpdateIsKeyDown(true);
				break;

			case SDLK_s:
				SKeyCode.UpdateIsKeyDown(true);
				break;

			case SDLK_d:
				DKeyCode.UpdateIsKeyDown(true);
				break;
			}
		}
		else if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				WKeyCode.UpdateIsKeyDown(false);
				break;

			case SDLK_a:
				AKeyCode.UpdateIsKeyDown(false);
				break;

			case SDLK_s:
				SKeyCode.UpdateIsKeyDown(false);
				break;

			case SDLK_d:
				DKeyCode.UpdateIsKeyDown(false);
				break;
			}
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				MouseState.SetIsLeftMouseButtonDown(true);
			}
			else if (event.button.button == SDL_BUTTON_RIGHT)
			{
				MouseState.SetIsRightMouseButtonDown(true);
			}
		}
		else if (event.type == SDL_MOUSEBUTTONUP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				MouseState.SetIsLeftMouseButtonDown(false);
			}
			else if (event.button.button == SDL_BUTTON_RIGHT)
			{
				MouseState.SetIsRightMouseButtonDown(false);
			}
		}
	}
}