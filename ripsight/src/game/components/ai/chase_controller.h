#ifndef CHASE_CONTROLLER_H
#define CHASE_CONTROLLER_H

#include "engine.h"

class ChaseController : public engine::Component
{
public:
	ChaseController(engine::Actor* owner, float chaseSpeed) : engine::Component(owner) 
	{
		m_ChaseSpeed = chaseSpeed;
	}

	void Birth() override;
	void OnTick(float deltaTime) override;

private:
	engine::Transform* m_TargetTransform = nullptr;
	engine::SpriteRenderer* m_SpriteRenderer = nullptr;
	engine::Transform* m_OwnerTransform = nullptr;
	float m_ChaseSpeed = 0.0f;
};

#endif // !CHASE_CONTROLLER_H