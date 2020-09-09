#include "input.h"

namespace engine
{
	KeyCode Input::WKeyCode;
	KeyCode Input::AKeyCode;
	KeyCode Input::SKeyCode;
	KeyCode Input::DKeyCode;

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
	}
}