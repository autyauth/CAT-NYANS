#pragma once
#include"Header.h"
class Bullet
{
private:
	Sprite bulletSprite;

	Vector2f direction;
	
	float movement;

public:
	void inTexture();
	Bullet(Texture &bulletTex,float positionX,float positionY,float directionX,float directionY,float speed);
	~Bullet();
	FloatRect getBounds();
	void update();
	void renderBullet(RenderWindow * target);
};

