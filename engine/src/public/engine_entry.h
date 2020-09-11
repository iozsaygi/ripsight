#ifndef ENGINE_ENTRY_H
#define ENGINE_ENTRY_H

#include <string>
#include <SDL.h>

namespace engine
{
	// Contains references about engine and handles the dependencies.
	class EngineEntry
	{
	public:
		EngineEntry(const std::string& title, const int windowWidth, const int windowHeight, 
			const int targetFPS);
		~EngineEntry();

		int GetTargetFPS();
		int GetWindowWidth();
		int GetWindowHeight();
		SDL_Renderer* GetRenderer();

	private:
		int m_TargetFPS = 0;
		int m_WindowWidth = 0;
		int m_WindowHeight = 0;
		SDL_Window* m_Window = nullptr;
		SDL_Renderer* m_Renderer = nullptr;
	};
}

#endif // !ENGINE_ENTRY_H