#include "Entity.h"



//void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
//{
//		target.draw(spriteSheet, states);
//}

Entity::Entity()
{
	texture.loadFromFile(textureFileName);

	//spriteSheet.setTexture(texture);
	//spriteSheet.setTextureRect(sf::IntRect(0, 0, 32, 32));

}


Entity::~Entity()
{

}

void Entity::setTextureName(string fileName)
{
	this->textureFileName = fileName;
}

string Entity::getTextureName()
{
	return this->textureFileName;
}

void Entity::loadTexture()
{
	texture.loadFromFile(getTextureName());
}

sf::Texture Entity::getTexture()
{
	return this->texture;
}

//void Entity::setRectSourceSprite(int q, int w, int e, int r)
//{
//	this->rectSourceSprite
//}


