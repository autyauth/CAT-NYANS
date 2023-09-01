#pragma once
#include"Header.h"

class Cat
{
private:

	float movementEnemy;
	Vector2f directionEnemy;

public:
	
	Cat(Texture& EnemyTexture, float positionEnemy_x, float positionEnemy_y, float directionEmnemy_x, float directionEmnemy_y, float speedEnemy);
	~Cat();
	Sprite cat1;
	FloatRect getBoundsEnemy();
	void moveUp();
	void moveDown();
	void updateEnemy(float deltaTime);
	void renderEnemy(RenderWindow* target);
};

