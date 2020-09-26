#include <assert.h>
#include <iostream>
#include "player.h"

void Player::AddScore(int value)
{
	assert(value > 0);
	m_Score += value;
}

int Player::GetScore()
{
	return m_Score;
}

void Player::SetScore(int value)
{
	m_Score = value;
}