#ifndef BUTTON_H
#define BUTTON_H

#include "engine.h"

class Button : public engine::Component
{
public:
	inline Button(engine::Actor* owner) : Component(owner) {}

	void Birth() override;
	void OnTick(float deltaTime) override;

private:
	engine::Transform* m_Transform = nullptr;
};

#endif // s!BUTTON_H