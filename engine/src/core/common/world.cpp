#include <assert.h>
#include <SDL.h>
#include "world.h"

namespace engine
{
	World::World(EngineEntry* engineEntry)
	{
		assert(engineEntry != nullptr);
		m_EngineEntry = engineEntry;
	}

	World::World(EngineEntry* engineEntry, bool isActive)
	{
		assert(engineEntry != nullptr);
		m_EngineEntry = engineEntry;
		m_IsActive = isActive;
	}

	void World::Tick()
	{
		const int frameDelay = 1000 / m_EngineEntry->GetTargetFPS();
		Uint32 frameStart = 0;
		int frameTime = 0;

		while (m_IsActive)
		{
			frameStart = SDL_GetTicks();

			ProcessEvents();
			Render();

			frameTime = SDL_GetTicks() - frameStart;
			if (frameDelay > frameTime)
				SDL_Delay(frameDelay - frameTime);
		}
	}

	void World::ProcessEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				m_IsActive = false;
		}
	}

	void World::Render()
	{
		auto renderer = m_EngineEntry->GetRenderer();
		if (renderer != nullptr)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			// Render actors here.

			SDL_RenderPresent(renderer);
		}
	}
}