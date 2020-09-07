#include <assert.h>
#include <SDL.h>
#include "world.h"

namespace engine
{
	World::World(EngineEntry* engineEntry)
	{
		assert(engineEntry != nullptr);
		m_EngineEntry = engineEntry;
		m_Actors = std::vector<Actor*>();
		m_RenderQueue = std::vector<SpriteRenderer*>();
	}

	World::World(EngineEntry* engineEntry, bool isActive)
	{
		assert(engineEntry != nullptr);
		m_EngineEntry = engineEntry;
		m_Actors = std::vector<Actor*>();
		m_RenderQueue = std::vector<SpriteRenderer*>();
		m_IsActive = isActive;
	}

	World::~World()
	{
		for (auto actor : m_Actors)
			delete actor;

		m_Actors.clear();
		m_RenderQueue.clear();
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
	}

	void World::AddActorRuntime(Actor* actor)
	{
		assert(actor != nullptr);
		m_Actors.push_back(actor);

		// Trigger the components of given actor.
		auto components = actor->GetComponents();
		for (auto component : components)
			component->Birth();

		for (auto component : components)
			component->Begin();
	}

	void World::SubscribeToRenderQueue(SpriteRenderer* spriteRenderer)
	{
		assert(spriteRenderer != nullptr);
		spriteRenderer->UpdateRenderer(m_EngineEntry->GetRenderer());
		m_RenderQueue.push_back(spriteRenderer);
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

			// Render actors here.
			for (auto spriteRenderer : m_RenderQueue)
				spriteRenderer->Render(renderer);

			SDL_RenderPresent(renderer);
		}
	}
}