#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
class Bullet
{
public:
	int x,y;
	Texture texB;;
	Sprite spriteB;
	int rotate;
	int angle;
	Bullet()
	{
		x=0;
		y=0;
		rotate=0;
		angle=0;
		texB.loadFromFile("img2/greenLaser.png");
		spriteB.setTexture(texB);
	}
	Bullet(int x,int y,int RotateB)
	{
		this->rotate=RotateB;
		if(rotate==1)
		{
			angle=45;
			texB.loadFromFile("img2/right.png");
			spriteB.setTexture(texB);
			this->x=x+50;
			this->y=y;
			spriteB.setPosition(this->x,this->y);
			spriteB.setScale(0.75,0.75);
		}
		else if(rotate==2)
		{
			angle=135;
			texB.loadFromFile("img2/left.png");
			spriteB.setTexture(texB);
			this->x = x;
			this->y = y-5;
			spriteB.setPosition(this->x, this->y);
			spriteB.setScale(0.75, 0.75);
		}
		else if (rotate == 3)
		{
			angle = 60;
			texB.loadFromFile("img2/30.png");
			spriteB.setTexture(texB);
			this->x = x+40;
			this->y = y-10 ;
			spriteB.setPosition(this->x, this->y);
			spriteB.setScale(0.75, 0.75);
		}
		else if (rotate == 4)
		    {
			angle = 120;
			texB.loadFromFile("img2/-30.png");
			spriteB.setTexture(texB);
			this->x = x;
			this->y = y - 3;
			spriteB.setPosition(this->x, this->y);
			spriteB.setScale(0.75, 0.75);
		}
		else if (rotate == 5)
		{
			angle = 75;
			texB.loadFromFile("img2/15.png");
			spriteB.setTexture(texB);
			this->x = x+30;
			this->y = y-10;
			spriteB.setPosition(this->x, this->y);
			spriteB.setScale(0.75, 0.75);
		}
		else if (rotate == 6)
		{
			angle = 105;
			texB.loadFromFile("img2/-15.png");
			spriteB.setTexture(texB);
			this->x = x;
			this->y = y - 1.5;
			spriteB.setPosition(this->x, this->y);
			spriteB.setScale(0.75, 0.75);
		}
		else
		{
			angle=90;
			texB.loadFromFile("img2/greenLaser.png");
			spriteB.setTexture(texB);
			this->x=x+15;
			this->y=y-15;
			spriteB.setPosition(this->x,this->y);
			spriteB.setScale(0.75,0.75);
		}
	}

	void operator=(const Bullet& b)
	{
		rotate=b.rotate;
		texB=b.texB;
		spriteB=b.spriteB;
		this->angle=b.angle;
		int x=b.spriteB.getPosition().x;
		int y=b.spriteB.getPosition().y;
		spriteB.setPosition(x,y);
		spriteB.setScale(0.75,0.75);
	}

};
