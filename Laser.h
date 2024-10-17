#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
class Laser
{
public:
	Texture texL;
	Sprite spriteL;
	int x;
	float speedL=-0.2;
	Laser(int x)
	{
		this->x=x;
		texL.loadFromFile("img/PNG/Lasers/laserGreen06.png");
		spriteL.setTexture(texL);
		spriteL.setPosition(x+100,100);
		spriteL.setScale(1,13);


	}
};


