#include "Enemya.h"

Enemya::Enemya(Texture& EnemyTexture, float positionEnemy_x, float positionEnemy_y, float directionEmnemy_x, float directionEmnemy_y, float speedEnemy)
{
	movementEnemy = speedEnemy;
	Enemy2.setTexture(EnemyTexture);
	Enemy2.setPosition(positionEnemy_x, positionEnemy_y);
	Enemy2.setScale(0.02f,0.02f);
	directionEnemy.x = directionEmnemy_x;
	directionEnemy.y = directionEmnemy_y;
}

Enemya::~Enemya()
{
}

FloatRect Enemya::getBoundsEnemy2()
{
	return Enemy2.getGlobalBounds();
}

void Enemya::updateEnemy2(float deltaTime)
{
	Enemy2.move(directionEnemy * movementEnemy*deltaTime);
}

void Enemya::renderEnemy2(RenderWindow* target)
{
	target->draw(Enemy2);
}
