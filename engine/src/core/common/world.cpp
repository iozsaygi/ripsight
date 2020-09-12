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
		m_CollidersInWorld = std::vector<BoxCollider2D*>();
	}

	World::World(EngineEntry* engineEntry, bool isActive)
	{
		assert(engineEntry != nullptr);
		m_EngineEntry = engineEntry;
		m_Actors = std::vector<Actor*>();
		m_CollidersInWorld = std::vector<BoxCollider2D*>();
		m_IsActive = isActive;
	}

	World::~World()
	{
		for (auto actor : m_Actors)
			delete actor;

		m_Actors.clear();
		m_CollidersInWorld.clear();
	}

	void World::Tick()
	{
		// Initialize colliders.
		for (auto actor : m_Actors)
		{
			BoxCollider2D* boxCollider2D = actor->GetComponent<BoxCollider2D>();
			if (boxCollider2D != nullptr)
				m_CollidersInWorld.push_back(boxCollider2D);
		}

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
			HandleCollisions();
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

	void World::HandleCollisions()
	{
		for (int i = 0; i < m_CollidersInWorld.size(); i++)
		{
			if (i + 1 < m_CollidersInWorld.size())
			{
				if (SDL_HasIntersection(&m_CollidersInWorld[i]->GetColliderRectangle(), &m_CollidersInWorld[i + 1]->GetColliderRectangle()))
				{
					for (auto component : m_CollidersInWorld[i]->GetOwner()->GetComponents())
						component->OnCollision(m_CollidersInWorld[i + 1]->GetOwner());

					for (auto component : m_CollidersInWorld[i + 1]->GetOwner()->GetComponents())
						component->OnCollision(m_CollidersInWorld[i]->GetOwner());
				}
			}
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