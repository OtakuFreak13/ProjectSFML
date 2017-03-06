#include "Game.h"
#include<iostream>


Game::Game()//kanske ska ha player eller enemy här
{

	backgroundTex.loadFromFile("Image/16bitmap.jpg");
	backgroundSprite.setTexture(backgroundTex);
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(backgroundSprite, states);
	target.draw(player, states);
	target.draw(enemy, states);
	//target.draw(ball);
}

void Game::Update(float dt)
{
	player.Update(dt);
	enemy.Update(dt);

	collision();

}


void  Game::collision()
{

	sf::Time delayInt = this->delayTime.restart(); //.asSeconds()
	time += delayInt;
	time2 += delayInt;
	if (player.getSpriteSheet().getGlobalBounds().intersects(enemy.getSpriteSheet().getGlobalBounds()))
	{
		//std::cout << "The sprites have collided!" << endl;
		//player.setCollided(true);
		//enemy.setCollided(true); 

		if (this->time.asSeconds() >= 2)
		{
			if (/*!player.getWasAttacking() && !player.getIsAttacking() && */sf::Keyboard::isKeyPressed(sf::Keyboard::Space)  /*sf::Keyboard::isKeyPressed(sf::Keyboard::Space)*/)
			{
				enemy.recevieDamage(player.attack());
				player.setIsAttacking(true);
				time = sf::Time();
				//delay.restart();
			}
			else if (!player.getWasAttacking() && player.getIsAttacking())
			{
				player.setIsAttacking(false);
				player.setWasAttacking(true);
			}
			else
			{
				player.setWasAttacking(false);
			}
			if (/*!enemy.getWasAttacking() && !enemy.getIsAttacking()*/this->time2.asSeconds() >= 2.5 && enemy.getHealth()>0 /*&& sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)*/)
			{
				player.recevieDamage(enemy.attack());
				enemy.setIsAttacking(true);
				time2 = sf::Time();
			}
			else
			{
				enemy.setIsAttacking(false);

			}
		}

		//sf::Event event();
		//sf::Event::KeyReleased;	
		//bool wasButtonReleased = false;
		//switch (event().key.code)
		//{
		//case sf::Keyboard::Space:
		//	wasButtonReleased = true;
		//	break;

		//default:
		//	break;
		//}


		//if (event.type == sf::Event::KeyReleased)
		//{
		//	if (event.key.code == sf::Keyboard::Space)
		//	{

		//	}
		//}

	}
	//else
	//{
	//	player.setCollided(false);
	//	enemy.setCollided(false);
	//}
}
