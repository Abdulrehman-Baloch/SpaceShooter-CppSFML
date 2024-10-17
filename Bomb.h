#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
class Bomb
{
public:
	Texture texBo;
	Sprite spriteBo;
	int x,y;
	Bomb(){
		x=0;y=0;
	}
	Bomb(int x,int y)
	{
		texBo.loadFromFile("img2/enemy_laser.png");
		spriteBo.setTexture(texBo);
		this->x=x+30;
		this->y=y-15;
		spriteBo.setPosition(this->x,this->y);
		spriteBo.setScale(1,1);
	}
	void operator=(const Bomb& b)
	{
		texBo.loadFromFile("img2/enemy_laser.png");
		spriteBo.setTexture(texBo);
		int x=b.spriteBo.getPosition().x;
		int y=b.spriteBo.getPosition().y;
		spriteBo.setPosition(x,y);
		spriteBo.setScale(1,1);
	}
};


