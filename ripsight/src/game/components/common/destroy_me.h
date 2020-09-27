#ifndef DESTROY_ME
#define DESTROY_ME

#include <assert.h>
#include "engine.h"

class DestroyMe : public engine::Component
{
public:
	inline DestroyMe(engine::Actor* owner, float lifeTime) : Component(owner)
	{
		assert(lifeTime > 0.0f);
		m_LifeTime = lifeTime;
	}

	inline void OnTick(float deltaTime)
	{
		if ( !m_DestroyTriggered )
		{
			m_Timer += deltaTime;
			if ( m_Timer >= m_LifeTime )
			{
				GetOwner()->GetOwnerWorld()->ScheduleActorForDestroy( GetOwner() );
				m_DestroyTriggered = true;
			}
		}
	}

private:
	float m_LifeTime = 0.0f;
	float m_Timer = 0.0f;
	bool m_DestroyTriggered = false;
};

#endif // !DESTROY_ME