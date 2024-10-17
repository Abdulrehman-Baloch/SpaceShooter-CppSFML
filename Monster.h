#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include"Enemy.h"
class Monster: public Enemy
{
public:

	Monster()
	{
		texE.loadFromFile("img2/monster.png");
		spriteE.setTexture(texE);
		spriteE.setPosition(250,0);
		spriteE.setScale(0.2,0.2);
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


