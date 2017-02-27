#include "Player.h"



Player::Player(): Entity()
{

	// Initialise animation variables.
	currentKeyFrame = sf::Vector2i(0, 0);
	keyFrameSize = sf::Vector2i(32, 32);
	animationSpeed = 0.2f;
	keyFrameDuration = 0.0f;
	//attackDamage= //inte helt säker på hur/var jag ska ha hrlat och damage 
}


void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(spriteSheet, states);
}

Player::~Player()
{

}

void Player::Update(float dt, float x = 1.0f, float y = 1.0f)
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
