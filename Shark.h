#pragma once
#include"Header.h"
class Shark
{
private:
	float movementEnemy;
	Vector2f directionEnemy;
public:
	Shark(Texture& EnemyTexture, float positionEnemy_x, float positionEnemy_y, float directionEmnemy_x, float directionEmnemy_y, float speedEnemy);
	~Shark();
	Sprite sharkSprite;
	FloatRect getBoundsEnemy();
	void updateEnemy(float deltaTime);
	void renderEnemy(RenderWindow* target);
	
};

