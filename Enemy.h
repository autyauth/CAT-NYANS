#pragma once
#include"Header.h"
class Enemy
{
private:
	
	float movementEnemy;
	Vector2f directionEnemy;



public:
	Sprite Enemy1;
	Enemy(Texture &EnemyTexture,float positionEnemy_x, float positionEnemy_y,float directionEmnemy_x, float directionEmnemy_y,float speedEnemy);
	~Enemy();
	FloatRect getBoundsEnemy();
	void updateEnemy();
	void renderEnemy(RenderWindow* target);

};

