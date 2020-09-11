#ifndef COMPONENT_H
#define COMPONENT_H

namespace engine
{
	class Actor;

	// Components are basic piece of any actor.
	class Component
	{
	public:
		Component(Actor* owner) 
		{
			if (m_Owner == nullptr)
				m_Owner = owner;;
		}

		virtual ~Component() {}

		// Will be called before world starts ticking. (Only once)
		inline virtual void Birth() {}

		// Will be called after the "Birth" function. (Only once)
		inline virtual void Begin() {}

		// Will be called every frame.
		inline virtual void OnTick(float deltaTime) {}

		// Will be called when world gets disabled. (Only once)
		inline virtual void OnShutdown() {}

		inline Actor* GetOwner() { return m_Owner; }
		inline void SetOwner(Actor* actor) { m_Owner = actor; }

	private:
		Actor* m_Owner = nullptr;
	};
}

#endif // !COMPONENT_H