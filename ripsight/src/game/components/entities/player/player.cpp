#include <assert.h>
#include <iostream>
#include "player.h"

void Player::AddScore(int value)
{
	assert(value > 0);
	m_Score += value;
	std::cout << "Current score: " << GetScore() << std::endl;
}

int Player::GetScore()
{
	return m_Score;
}