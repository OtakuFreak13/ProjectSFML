#ifndef GAME_H
#define GAME_H
#include "SFML\Graphics.hpp"
#include"Player.h"
#include"Enemy.h"


class Game :public sf::Drawable
{
private:
	sf::Texture backgroundTex;
	sf::Sprite backgroundSprite;
	Player player;
	Enemy enemy;
	sf::CircleShape ball;

	sf::Clock delayTime;
	sf::Time time;
	sf::Time time2;
	
	
	void collision();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;	
public:
Game();

	void Update(float dt);
};

#endif //  !GAME_H