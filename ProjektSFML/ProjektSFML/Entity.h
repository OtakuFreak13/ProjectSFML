#ifndef ENTITY_H
#define ENTITY_H

#include"SFML\Graphics.hpp"
#include<string>

using namespace std;

class Entity
{
private:
	sf::Texture texture;
	string textureFileName;
	//sf::Sprite spriteSheet; //kanske ska vara h�r inte s�ker
	sf::RectangleShape rect;
	//sf::IntRect rectSourceSprite;

	//void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Entity();
	virtual ~Entity();
	//virtual void Update(float dt, float x = 1.0f, float y = 1.0f) = 0;//Om jag inte ska ha denna klass f�r items s� kan jag ha med denna raden.
	void setTextureName(string fileName);
	//void setRectSourceSprite(int q, int w, int e, int r);
};

#endif // !ENTITY_H