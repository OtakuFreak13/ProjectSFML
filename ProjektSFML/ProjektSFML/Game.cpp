#include "Game.h"
#include<iostream>


Game::Game()//kanske ska ha player eller enemy här
{

	this->lengthOfEnemyArr = 10;
	this->enemies = new Enemy*[this->lengthOfEnemyArr];

	this->EnemiesInArr = 0;
	this->enemies[this->EnemiesInArr++] = new Enemy();

	

	//Enemy *lol = new Enemy();

	//for (int i = 0; i < this->lengthOfEnemyArr; i++)
	//{
	//	this->enemies[i] = new Enemy();
	//}

	backgroundTex.loadFromFile("Image/16bitmap.jpg");
	backgroundSprite.setTexture(backgroundTex);
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(backgroundSprite, states);
	target.draw(player, states);
	this->renderEnemies(target, states);
	
	
	//target.draw(ball);
}

void Game::Update(float dt)
{
	player.Update(dt);
	//enemies[(this->EnemiesInArr - 1) + this->deathCounter()]->Update(dt);

	for (int i = 0; i < this->EnemiesInArr; i++)
	{
		//enemies[(this->EnemiesInArr - 1)]->Update(dt);
		enemies[i]->Update(dt);
	}
	
	
	if (!player.death())
	{
		collision();
	}

	if (enemies[(this->EnemiesInArr - 1)]->death()) {

		this->EnemiesInArr++;

		Enemy *myEnemy = new Enemy();

		enemies[EnemiesInArr-1] = myEnemy;

		//int deaths = this->deathCounter();
		//int arrPos = (this->EnemiesInArr - 1);
 		//enemies[arrPos + deaths] = new Enemy();
	}


}


int Game::deathCounter() const
{
	int deaths = 0;
	for (int i = 0; i < this->EnemiesInArr; i++)
	{
		if (enemies[i]->death() ) //== true
		{
			deaths++;
		}
	}

	
	return deaths;
}

void Game::renderEnemies(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < this->EnemiesInArr; i++) {

		//if (!this->enemies[i]->death()) {
			target.draw(*enemies[i], states);		
		//}
	}
	
	

}

void  Game::collision()
{

	sf::Time delayInt = this->delayTime.restart(); //.asSeconds()
	time += delayInt;
	time2 += delayInt;

	for (int i = 0; i < this->EnemiesInArr; i++)
	{
		if (enemies[i]->death()) {
				//do nothign
		}else if (player.getSpriteSheet().getGlobalBounds().intersects(enemies[i]->getSpriteSheet().getGlobalBounds()))
		{
			//std::cout << "The sprites have collided!" << endl;
			//player.setCollided(true);
			//enemy.setCollided(true); 

			if (this->time.asSeconds() >= 2)
			{
				if (/*!player.getWasAttacking() && !player.getIsAttacking() && */sf::Keyboard::isKeyPressed(sf::Keyboard::Space)  /*sf::Keyboard::isKeyPressed(sf::Keyboard::Space)*/)
				{
					enemies[i]->recevieDamage(player.attack());
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
				if (/*!enemy.getWasAttacking() && !enemy.getIsAttacking()*/this->time2.asSeconds() >= 2.5 && enemies[i]->getHealth()>0 /*&& sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)*/)
				{
					player.recevieDamage(enemies[i]->attack());
					enemies[i]->setIsAttacking(true);
					time2 = sf::Time();
				}
				else
				{
					enemies[i]->setIsAttacking(false);

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
	}
	
	//else
	//{
	//	player.setCollided(false);
	//	enemy.setCollided(false);
	//}
}
