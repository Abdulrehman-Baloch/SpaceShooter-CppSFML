#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
class Enemy
{
public:
	Texture texE;
	Sprite spriteE;
	float speedM=-0.2;
	virtual void Rectangle(Enemy** &E)=0;
	virtual void Triangle(Enemy** &E)=0;
	virtual void Heart(Enemy** &E)=0;
	virtual void Cross(Enemy** &E)=0;
	virtual void diamond(Enemy** &E)=0;
	virtual void filledRectangle(Enemy** &E)=0;
	virtual void filledTriangle(Enemy** &E)=0;
	virtual void filledDiamond(Enemy** &E)=0;
	//virtual void fireB()=0;
};




