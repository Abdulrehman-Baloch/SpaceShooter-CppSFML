#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include"Enemy.h"
class Dragon: public Enemy
{
public:
	Dragon()
	{
		texE.loadFromFile("img2/bestD.png");
		spriteE.setTexture(texE);
		spriteE.setPosition(200,0);
		spriteE.setScale(0.6,0.6);
	}
	virtual void Rectangle(Enemy** &E)
	{

	}
	virtual void Triangle(Enemy** &E)
	{

	}
	virtual void Heart(Enemy** &E)
	{

	}
	virtual void Cross(Enemy **&E)
	{

	}
	virtual void diamond(Enemy **&E)
	{

	}
	virtual void filledRectangle(Enemy** &E)
	{

	}
	virtual void filledTriangle(Enemy** &E)
	{

	}
	virtual void filledDiamond(Enemy** &E)
	{

	}

};

