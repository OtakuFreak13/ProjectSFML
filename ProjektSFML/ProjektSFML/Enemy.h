#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
class Enemy :
	public Entity
{
private:
	float enemySpeed = 180.0f;
public:
	Enemy(int enemyNr);
	~Enemy();
	void Update(float dt, float x = 1.0f, float y = 1.0f);
};

#endif // !ENEMY_H