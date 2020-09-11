#ifndef CHASE_CONTROLLER_H
#define CHASE_CONTROLLER_H

#include "engine.h"

class ChaseController : public engine::Component
{
public:
	ChaseController(engine::Actor* owner) : engine::Component(owner) {}

	void Birth() override;
	void OnTick(float deltaTime) override;

private:
	engine::Transform* m_TargetTransform = nullptr;
	engine::SpriteRenderer* m_SpriteRenderer = nullptr;
	engine::Transform* m_OwnerTransform = nullptr;
};

#endif // !CHASE_CONTROLLER_H