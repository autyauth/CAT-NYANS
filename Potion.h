#pragma once
#include"Header.h"
class Potion
{
private:

public:
	Sprite potionSprite;
	Potion(Texture& texture, float posiX, float posiY);
	~Potion();
	FloatRect getBounds();
	void setTex();
	void reder(RenderWindow* target);
	
};

