#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "engine.h"

class PlayerController : public engine::Component
{
public:
	PlayerController(engine::Actor* owner) : Component(owner) { m_Velocity = engine::Vector2D::One(); }
	PlayerController(engine::Actor* owner, const engine::Vector2D& velocity) : Component(owner) { m_Velocity = velocity; }

	void Birth() override;
	void OnTick(float deltaTime) override;

private:
	engine::Vector2D m_Velocity;
	engine::Transform* m_OwnerTransform = nullptr;
	engine::SpriteRenderer* m_OwnerSpriteRenderer = nullptr;
};

#endif // !PLAYER_CONTROLLER_H