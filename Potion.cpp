#include "Potion.h"

Potion::Potion(Texture& texture, float posiX, float posiY)
{
	potionSprite.setTexture(texture);
	potionSprite.setPosition(posiX,posiY);
	potionSprite.setScale(0.025f,0.025f);
	
}

Potion::~Potion()
{
}

FloatRect Potion::getBounds()
{
	return potionSprite.getGlobalBounds();
}

void Potion::setTex()
{
}

void Potion::reder(RenderWindow* target)
{
	target->draw(potionSprite);
}
