#include "engine_entry.h"

namespace engine
{
	EngineEntry::EngineEntry(const std::string& title, const int windowWidth, const int windowHeight, 
		const int targetFPS)
	{
		m_TargetFPS = targetFPS;

		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		{
			SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
			return;
		}

		if (SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_SHOWN, &m_Window, &m_Renderer))
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
			return;
		}

		SDL_SetWindowTitle(m_Window, title.c_str());
		SDL_Log("Engine entry created!");
	}

	EngineEntry::~EngineEntry()
	{
		SDL_Log("Shutting down engine entry!");

		SDL_DestroyRenderer(m_Renderer);
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
	}

	int EngineEntry::GetTargetFPS()
	{
		return m_TargetFPS;
	}

	SDL_Renderer* EngineEntry::GetRenderer()
	{
		return m_Renderer;
	}
}