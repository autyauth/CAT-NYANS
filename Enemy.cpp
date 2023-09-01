#include "Enemy.h"
Enemy::Enemy(Texture& EnemyTexture, float positionEnemy_x, float positionEnemy_y, float directionEmnemy_x, float directionEmnemy_y, float speedEnemy)
{
	movementEnemy = speedEnemy;
	Enemy1.setTexture(EnemyTexture);
	Enemy1.setPosition(positionEnemy_x,positionEnemy_y);
	directionEnemy.x = directionEmnemy_x;
	directionEnemy.y = directionEmnemy_y;
}

Enemy::~Enemy()
{
}

FloatRect Enemy::getBoundsEnemy()
{
	return Enemy1.getGlobalBounds();
}

void Enemy::updateEnemy()
{
	Enemy1.move(directionEnemy*movementEnemy);
}

void Enemy::renderEnemy(RenderWindow* target)
{
	target->draw(Enemy1);
}