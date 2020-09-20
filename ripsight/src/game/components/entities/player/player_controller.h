#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "engine.h"
#include "game/components/entities/weapons/weapon_controller.h"

class PlayerController : public engine::Component
{
public:
	PlayerController(engine::Actor* owner, engine::EngineEntry* engineEntry) : Component(owner) 
	{ 
		m_Velocity = engine::Vector2D::One();
		m_EngineEntry = engineEntry;
	}

	PlayerController(engine::Actor* owner, engine::EngineEntry* engineEntry, const engine::Vector2D& velocity) : Component(owner)
	{
		m_Velocity = velocity; 
		m_EngineEntry = engineEntry;
	}

	void Birth() override;
	void OnTick(float deltaTime) override;
	void OnCollision(engine::Actor* other);

private:
	engine::Vector2D m_Velocity;
	engine::Transform* m_OwnerTransform = nullptr;
	engine::SpriteRenderer* m_OwnerSpriteRenderer = nullptr;
	WeaponController* m_WeaponController = nullptr;
	engine::EngineEntry* m_EngineEntry = nullptr;
	engine::Actor* m_ReviveButton = nullptr;
};

#endif // !PLAYER_CONTROLLER_H