#ifndef PLAYER_H
#define PLAYER_H

#include "engine.h"

class Player : public engine::Component
{
public:
	inline Player(engine::Actor* owner) : Component(owner) {}

	void AddScore(int value);
	int GetScore();
	void SetScore(int value);

private:
	int m_Score = 0;
};

#endif // !PLAYER_H