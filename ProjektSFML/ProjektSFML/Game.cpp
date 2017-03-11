#include "Game.h"



Game::Game()//kanske ska ha player eller enemy h�r
{

	this->lengthOfEnemyArr = 10;
	this->enemies = new Enemy*[this->lengthOfEnemyArr];

	this->EnemiesInArr = 0;
	this->enemies[this->EnemiesInArr++] = new Enemy();

	gameTime;
	this->gameOverCounter = 0;//TODO kanske ta bort gameOverCounter och set funktionen?

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
	this->gameOver(target, states);

	if (player.getHealth() > 0)
	{
		this->displayGameTime(target, states);
	}
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

		enemies[EnemiesInArr - 1] = myEnemy;

		//int deaths = this->deathCounter();
		//int arrPos = (this->EnemiesInArr - 1);
		//enemies[arrPos + deaths] = new Enemy();
	}

	if (!player.death())
	{
		this->intGameTime = this->gameTime.getElapsedTime();
	}
	setGameOverCounter();
	//if (gameOverCounter > 0)
	//{
	//	HighScore(deathCounter, intGameTime.asSeconds());
	//}
}

void Game::setGameOverCounter()
{
	if (player.death())
	{
		this->gameOverCounter++;
	}
}

int Game::getDeathCounter()const
{
	return this->deathCounter();
}

int Game::deathCounter() const
{
	int deaths = 0;
	for (int i = 0; i < this->EnemiesInArr; i++)
	{
		if (enemies[i]->death()) //== true
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

int Game::displayGameTime(sf::RenderTarget & target, sf::RenderStates states) const
{



	sf::Font font;
	if (!font.loadFromFile("Image/feather_script/FeatherScript.otf"))
	{
		// error...
	}
	sf::Text text;

	// select the font
	text.setFont(font); // font is a sf::Font


	string textString = to_string(intGameTime.asSeconds());
	// set the string to display
	text.setString(textString);

	// set the character size
	text.setCharacterSize(18); // in pixels, not points!

							   // set the color
	text.setFillColor(sf::Color::Black);

	// set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.move(20.0f, 20.0f);
	target.draw(text, states);

	return intGameTime.asSeconds();
}

void Game::gameOver(sf::RenderTarget & target, sf::RenderStates states) const
{

	if (this->player.getHealth() <= 0)
	{
		sf::Font font;
		if (!font.loadFromFile("Image/feather_script/FeatherScript.otf"))
		{
			// error...
		}
		sf::Text text;

		// select the font
		text.setFont(font); // font is a sf::Font

		int kills = deathCounter();
		string textString = "Player is dead! \nConfirmed kills: " + to_string(kills) + "\nTime in game; " + to_string(this->intGameTime.asSeconds());
		// set the string to display
		text.setString(textString);

		// set the character size
		text.setCharacterSize(24); // in pixels, not points!

								   // set the color
		text.setFillColor(sf::Color::Black);

		// set the text style
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		text.move(200.0f, 200.0f);
		target.draw(text, states);
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
		}
		else if (player.getSpriteSheet().getGlobalBounds().intersects(enemies[i]->getSpriteSheet().getGlobalBounds()))
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
				if (/*!enemy.getWasAttacking() && !enemy.getIsAttacking()*/this->time2.asSeconds() >= 2.5 && enemies[i]->getHealth() > 0 /*&& sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)*/)
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
