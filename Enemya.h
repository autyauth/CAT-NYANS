#pragma once
#include"Header.h"
class Enemya
{
private:

	float movementEnemy;
	Vector2f directionEnemy;



public:
	Enemya(Texture& EnemyTexture, float positionEnemy_x, float positionEnemy_y, float directionEmnemy_x, float directionEmnemy_y, float speedEnemy);
	~Enemya();
	Sprite Enemy2;
	FloatRect getBoundsEnemy2();
	void updateEnemy2(float deltaTime);
	void renderEnemy2(RenderWindow* target);
};

