#include "Enemy.h"



Enemy::Enemy(int enemyNr) : Entity()
{

}


Enemy::~Enemy()
{

}

void Enemy::Update(float dt, float x, float y)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction.x = -x;
		keyFrameDuration += dt;
		currentKeyFrame.y = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction.x = x;
		keyFrameDuration += dt;
		currentKeyFrame.y = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction.y = y;
		keyFrameDuration += dt;
		currentKeyFrame.y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction.y = -y;
		keyFrameDuration += dt;
		currentKeyFrame.y = 3;
	}
}
