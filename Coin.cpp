#include "Coin.h"

Coin::Coin(Texture& texture, float posiX, float posiY)
{
	coinSprite.setTexture(texture);
	coinSprite.setPosition(posiX,posiY);
	coinSprite.setScale(0.1f,0.1f);
	
}

Coin::~Coin()
{
}

FloatRect Coin::getBounds()
{
	return coinSprite.getGlobalBounds();
}

void Coin::setTex()
{

}

void Coin::reder(RenderWindow* target)
{
	target->draw(coinSprite);
}
