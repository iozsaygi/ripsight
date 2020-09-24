#ifndef CROSSHAIR_H
#define CROSSHAIR_H

#include "engine.h"

class Crosshair : public engine::Component
{
public:
	inline Crosshair(engine::Actor* owner) : Component(owner) {}

	void Birth() override;
	void OnTick(float deltaTime) override;

private:
	engine::Transform* m_OwnerTransform = nullptr;
};

#endif // !CROSSHAIR_H