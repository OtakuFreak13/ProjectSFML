#include "Game.h"



Game::Game() //kanske ska ha player eller enemy här
{
	backgroundTex.loadFromFile("Image/16bitmap.png");
	backgroundSprite.setTexture(backgroundTex);
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(backgroundSprite, states);
	target.draw(player, states);
	target.draw(enemy, states);
}

void Game::Update(float dt)
{
	player.Update(dt);
	enemy.Update(dt);
}



