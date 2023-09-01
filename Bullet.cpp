#include "Bullet.h"

void Bullet::inTexture()
{
	
}

Bullet::Bullet(Texture &bulletTex, float positionX, float positionY, float directionX, float directionY,float speed)
{
	movement = speed;
	bulletSprite.setTexture(bulletTex);
	bulletSprite.setPosition(positionX,positionY);
	direction.x = directionX;
	direction.y = directionY;
	bulletSprite.setScale(0.05f,0.05f);
}	

Bullet::~Bullet()
{

}

FloatRect Bullet::getBounds()
{
	//คืนค่าพวก จุด x y height widght 
	return bulletSprite.getGlobalBounds();
}


void Bullet::update()
{
	bulletSprite.move(direction*movement);
}

void Bullet::renderBullet(RenderWindow* target)
{
	target->draw(bulletSprite);
}

