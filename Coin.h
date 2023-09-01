#pragma once
#include"Header.h"
class Coin
{
private:

	
	
public:
	
	Sprite coinSprite;
	Coin(Texture &texture,float posiX,float posiY);
	~Coin();
	FloatRect getBounds();
	void setTex();
	void reder(RenderWindow* target);
	
};

