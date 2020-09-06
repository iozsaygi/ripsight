#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "public/engine_entry.h"
#include "core/common/actor.h"

namespace engine
{
	// Contains entities and updates the game state frame by frame.
	class World
	{
	public:
		World(EngineEntry* engineEntry);
		World(EngineEntry* engineEntry, bool isActive);

		// Will be called every frame to update components of actors in world.
		void Tick();

		// Adds given actor to world. 
		void AddActor(Actor* actor);

		// Adds given actor to the world. Only call while the game/engine is running.
		void AddActorRuntime(Actor* actor);

	private:
		bool m_IsActive = false;
		EngineEntry* m_EngineEntry = nullptr;
		std::vector<Actor*> m_Actors;

		void ProcessEvents();
		void UpdateActors(float deltaTime);
		void Render();
	};
}

#endif // !WORLD_H