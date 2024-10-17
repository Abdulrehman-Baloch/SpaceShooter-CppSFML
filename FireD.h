#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
class FireD
{
public:
	Texture texF;
	Sprite spriteF;
	Sprite tempF;

	FireD()
	{

			texF.loadFromFile("img2/fire.png");
			spriteF.setTexture(texF);
			spriteF.setPosition(180,150);
			spriteF.setScale(1,3);
	}

};


