#include "Enemy.h"



Enemy::Enemy() : Entity()
{
	//	setTextureName("Image/goblinsword.png");
		/*sf::Texture texture;*/
	if (!texture.loadFromFile("Image/goblinSwordBlue.png"))
	{
		// handle error
	}
	//loadTexture();
	spriteSheet.setTexture(texture);
	spriteSheet.setTextureRect(sf::IntRect(0, 0, 64, 64));
	spriteSheet.setPosition(sf::Vector2f(385, 0));
	currentKeyFrame = sf::Vector2i(0, 0);
	keyFrameSize = sf::Vector2i(64, 64);
	spriteSheetWidth = 7;
	/*spriteSheetHeight = 4;*/
	animationSpeed = 0.1f;
	keyFrameDuration = 0.0f;

	srand(time(NULL));

	attackDamage = (rand() % 3) + 1;
	health = (rand() % 10) + 1;


}


Enemy::~Enemy()
{

}

void Enemy::move(float dt)
{
	//float x = 1.0f;
	//float y = 1.0f;
	//sf::Vector2f direction(0.0f, 0.0f);
	//direction.x = -x;
	//keyFrameDuration += dt;
	//currentKeyFrame.y = 3;

	//sf::Vector2f playerPosition = Game().player.GetPosition();
	//sf::Vector2f thisPosition;
	//thisPosition.x = xPos;
	//thisPosition.y = yPos;
}
void Enemy::Update(float dt)
{
	float x = 1.0f;
	float y = 1.0f;


	sf::Vector2f direction(0.0f, 0.0f);
	int moveDirection = rand() % 10;
	if (this->health <= 0)
	{
		// death animation
		currentKeyFrame.y = 4;
		keyFrameDuration += 0.5 * dt;
		if (keyFrameDuration >= animationSpeed)
		{
			currentKeyFrame.x++;

			if (currentKeyFrame.x >= 5)
			{
				currentKeyFrame.x = 5;
			}

			spriteSheet.setTextureRect(sf::IntRect(currentKeyFrame.x * keyFrameSize.x, currentKeyFrame.y * keyFrameSize.y, keyFrameSize.x, keyFrameSize.y));
			keyFrameDuration = 0.0f;
		}
	}
	else
	{
		if (moveDirection == 0)
		{
			switch ((rand() % 5))
			{
			case 1:
				move(dt);
				break;
			case 2:
				move(dt); move(dt);
				break;
			case 3:
				move(dt); move(dt); move(dt);
				break;
			case 4:
				move(dt); move(dt); move(dt); move(dt);
				break;
			default:
				break;

			}
			if (moveDirection == 1)
			{
				direction.x = x;
				keyFrameDuration += dt;
				currentKeyFrame.y = 1;
			}
			if (moveDirection == 2)
			{
				direction.y = y;
				keyFrameDuration += dt;
				currentKeyFrame.y = 0;
			}
			if (moveDirection == 3)
			{
				direction.y = -y;
				keyFrameDuration += dt;
				currentKeyFrame.y = 2;
			}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
			//{
			//	direction.x = -x;
			//	keyFrameDuration += dt;
			//	currentKeyFrame.y = 3;
			//}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
			//{
			//	direction.x = x;
			//	keyFrameDuration += dt;
			//	currentKeyFrame.y = 1;
			//}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
			//{
			//	direction.y = y;
			//	keyFrameDuration += dt;
			//	currentKeyFrame.y = 0;
			//}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
			//{
			//	direction.y = -y;
			//	keyFrameDuration += dt;
			//	currentKeyFrame.y = 2;
			//}

			spriteSheet.move(direction * enemySpeed * dt);

			// Update animation
			if (keyFrameDuration >= animationSpeed)
			{
				currentKeyFrame.x++;

				if (currentKeyFrame.x >= spriteSheetWidth)
				{
					currentKeyFrame.x = 0;
				}

				spriteSheet.setTextureRect(sf::IntRect(currentKeyFrame.x * keyFrameSize.x, currentKeyFrame.y * keyFrameSize.y, keyFrameSize.x, keyFrameSize.y));
				keyFrameDuration = 0.0f;
			}
			//bool didCollide = this->getSprite().getGlobalBounds().intersects(platform->getPlatform()->getGlobalBounds());
			if (this->collided == true)
			{

			}
		}
	}
}

	void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		target.draw(spriteSheet, states);
	}

	sf::Sprite Enemy::getSpriteSheet()
	{
		return this->spriteSheet;
	}

	void Enemy::setCollided(int tf)
	{
		this->collided = tf;
	}

	bool Enemy::getWasAttacking()
	{
		return this->wasAttacking;
	}

	void Enemy::setWasAttacking(int tf)
	{
		this->wasAttacking = tf;
	}

	bool Enemy::getIsAttacking()
	{
		return this->isAttacking;
	}

	void Enemy::setIsAttacking(int tf)
	{
		this->isAttacking = tf;
	}

	int Enemy::attack()
	{
		//animate attack
		int randNum = rand() % 3;
		return attackDamage * randNum;
	}

	void Enemy::recevieDamage(int damage)
	{
		this->health -= damage;
		cout << damage << " Amount of damage enemy has revcieved! Remaining enemy health: " << this->health << endl;
	
			this->death();
	}

	bool Enemy::death()
	{
		// death animation
		bool dead = false;
		if (this->health <= 0)
		{
			dead = true;
		}
		return dead;
	}

	int Enemy::getHealth()
	{
		return this->health;
	}
