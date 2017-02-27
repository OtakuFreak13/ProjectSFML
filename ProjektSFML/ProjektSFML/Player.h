#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
class Player :
	public Entity
{
private:
	sf::Sprite spriteSheet;
	sf::IntRect rectSourceSprite;
	sf::Vector2i currentKeyFrame;
	sf::Vector2i keyFrameSize;
	float animationSpeed;
	float keyFrameDuration;
	float playerSpeed = 180.0f;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	int attackDamage;
	int health;
public:
	Player();
	~Player();
	void Update(float dt, float x = 1.0f, float y = 1.0f);
};

#endif // !PLAYER_H