#ifndef COMPONENT_H
#define COMPONENT_H

namespace engine
{
	// Components are basic piece of any actor.
	class Component
	{
	public:
		// Will be called before world starts ticking. (Only once)
		inline virtual void Birth() {}

		// Will be called after the "Birth" function. (Only once)
		inline virtual void Begin() {}

		// Will be called every frame.
		inline virtual void OnTick(float deltaTime) {}

		// Will be called when world gets disabled. (Only once)
		inline virtual void OnShutdown() {}
	};
}

#endif // !COMPONENT_H