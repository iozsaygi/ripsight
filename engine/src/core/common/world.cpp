#include <assert.h>
#include <SDL.h>
#include "core/event_system/input.h"
#include "world.h"

namespace engine
{
	World::World(EngineEntry* engineEntry)
	{
		assert(engineEntry != nullptr);
		m_EngineEntry = engineEntry;
		m_Actors = std::vector<Actor*>();
	}

	World::World(EngineEntry* engineEntry, bool isActive)
	{
		assert(engineEntry != nullptr);
		m_EngineEntry = engineEntry;
		m_Actors = std::vector<Actor*>();
		m_IsActive = isActive;
	}

	World::~World()
	{
		for (auto actor : m_Actors)
			delete actor;

		m_Actors.clear();
	}

	void World::Tick()
	{
		// That make a big mess...
		for (auto actor : m_Actors)
		{
			for (auto component : actor->GetComponents())
				component->Birth();
		}

		for (auto actor : m_Actors)
		{
			for (auto component : actor->GetComponents())
				component->Begin();
		}

		const int frameDelay = 1000 / m_EngineEntry->GetTargetFPS();
		Uint32 frameStart = 0;
		int frameTime = 0;

		while (m_IsActive)
		{
			float deltaTime = (SDL_GetTicks() - frameStart) / 1000.0f;
			frameStart = SDL_GetTicks();

			ProcessEvents();
			UpdateActors(deltaTime);
			Render();

			frameTime = SDL_GetTicks() - frameStart;
			if (frameDelay > frameTime)
				SDL_Delay(frameDelay - frameTime);
		}

		for (auto actor : m_Actors)
		{
			for (auto component : actor->GetComponents())
				component->OnShutdown();
		}
	}

	void World::AddActor(Actor* actor)
	{
		assert(actor != nullptr);
		m_Actors.push_back(actor);
		actor->SetOwnerWorld(this);
	}

	void World::ProcessEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				m_IsActive = false;

			Input::UpdateKeyStates(event);
		}
	}

	void World::UpdateActors(float deltaTime)
	{
		for (auto actor : m_Actors)
		{
			for (auto component : actor->GetComponents())
				component->OnTick(deltaTime);
		}
	}

	void World::Render()
	{
		auto renderer = m_EngineEntry->GetRenderer();
		if (renderer != nullptr)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			for (auto actor : m_Actors)
			{
				SpriteRenderer* spriteRenderer = actor->GetComponent<SpriteRenderer>();
				if (spriteRenderer != nullptr)
					spriteRenderer->Render(renderer);
			}

			SDL_RenderPresent(renderer);
		}
	}

	Actor* World::GetActorByName(const std::string& name)
	{
		for (auto actor : m_Actors)
		{
			if (actor != nullptr)
			{
				if (actor->GetName() == name)
					return actor;
			}
		}

		return nullptr;
	}
}