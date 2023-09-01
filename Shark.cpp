#include "Shark.h"

Shark::Shark(Texture& EnemyTexture, float positionEnemy_x, float positionEnemy_y, float directionEmnemy_x, float directionEmnemy_y, float speedEnemy)
{
	movementEnemy = speedEnemy;
	sharkSprite.setTexture(EnemyTexture);
	sharkSprite.setPosition(positionEnemy_x, positionEnemy_y);
	sharkSprite.setScale(0.1f, 0.1f);
	directionEnemy.x = directionEmnemy_x;
	directionEnemy.y = directionEmnemy_y;
}

Shark::~Shark()
{
}

FloatRect Shark::getBoundsEnemy()
{
	return sharkSprite.getGlobalBounds();
}

void Shark::updateEnemy(float deltaTime)
{
	sharkSprite.move(directionEnemy * movementEnemy * deltaTime);
}

void Shark::renderEnemy(RenderWindow* target)
{
	target->draw(sharkSprite);
}
