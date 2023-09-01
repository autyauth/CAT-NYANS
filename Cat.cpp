#include "Cat.h"

Cat::Cat(Texture& EnemyTexture, float positionEnemy_x, float positionEnemy_y, float directionEmnemy_x, float directionEmnemy_y, float speedEnemy)
{
	movementEnemy = speedEnemy;
	cat1.setTexture(EnemyTexture);
	cat1.setPosition(positionEnemy_x, positionEnemy_y);
	cat1.setScale(0.5f,0.5f);
	directionEnemy.x = directionEmnemy_x;
	directionEnemy.y = directionEmnemy_y;
}

Cat::~Cat()
{
}

FloatRect Cat::getBoundsEnemy()
{
	return cat1.getGlobalBounds();
}

void Cat::moveUp()
{
	directionEnemy.y = -0.1f;
	cat1.move(directionEnemy * movementEnemy);
}

void Cat::moveDown()
{
	directionEnemy.y = 0.1f;
	cat1.move(directionEnemy * movementEnemy);
}

void Cat::updateEnemy(float deltaTime)
{
	cat1.move(directionEnemy * movementEnemy*deltaTime);
}

void Cat::renderEnemy(RenderWindow* target)
{
	target->draw(cat1);
}
