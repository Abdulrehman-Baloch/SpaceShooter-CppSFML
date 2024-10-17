#pragma once
#include <SFML/Graphics.hpp>
#include"Bullet.h"
#include <string.h>
#include<cmath>
using namespace sf;
class Player
{
public:
	Texture tex;
	Sprite sprite;
	float speed = 1.3;
	int SizeB=0;
	int x, y;
	int lives;
	Bullet *&ptr;

	Player(std::string png_path , Bullet *&b):ptr(b)
	{
		lives=3;
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 340;
		y = 700;
		sprite.setPosition(x, y);
		sprite.setScale(0.6, 0.6);
	}

	void fire()
	{
		for(int i=0 ; i < SizeB; i++)
		{

		 if(ptr[i].rotate==1)
			{
				ptr[i].texB.loadFromFile("img2/right.png");
				ptr[i].spriteB.setTexture(ptr[i].texB);
				ptr[i].spriteB.setScale(0.75,0.75);

			}
		 else if(ptr[i].rotate==2)
			 {
				 ptr[i].texB.loadFromFile("img2/left.png");
				 ptr[i].spriteB.setTexture(ptr[i].texB);
				 ptr[i].spriteB.setScale(0.75,0.75);
			 }
		 else if (ptr[i].rotate == 3)
			 {
				ptr[i].texB.loadFromFile("img2/30.png");
				ptr[i].spriteB.setTexture(ptr[i].texB);
				ptr[i].spriteB.setScale(0.75, 0.75);
			 }
		 else if (ptr[i].rotate == 4)
			{
				ptr[i].texB.loadFromFile("img2/-30.png");
				ptr[i].spriteB.setTexture(ptr[i].texB);
				ptr[i].spriteB.setScale(0.75, 0.75);
			}
		 else if (ptr[i].rotate == 5)
			{
				ptr[i].texB.loadFromFile("img2/15.png");
				ptr[i].spriteB.setTexture(ptr[i].texB);
				ptr[i].spriteB.setScale(0.75, 0.75);
			}
		 else if (ptr[i].rotate == 6)
			{
				ptr[i].texB.loadFromFile("img2/-15.png");
				ptr[i].spriteB.setTexture(ptr[i].texB);
				ptr[i].spriteB.setScale(0.75, 0.75);
			}
		else
			 {
				ptr[i].texB.loadFromFile("img2/greenLaser.png");
				ptr[i].spriteB.setTexture(ptr[i].texB);
				ptr[i].spriteB.setScale(0.75, 0.75);

			 }
			float a = 10;
			float b = -10;
			float r = ptr[i].angle * 3.1416 / 180;
			ptr[i].spriteB.move(a * cos(r), b * sin(r));
		}
	}
	void rotate(std::string s)
	{
		if(s=="a")
		{
			tex.loadFromFile("img/dig/r.png");
			sprite.setTexture(tex); 
		}
		else if(s=="b")
		{
			tex.loadFromFile("img/dig/l.png");
			sprite.setTexture(tex);
		}
		else if(s=="c")
		{
			tex.loadFromFile("img/dig/lb.png");
			sprite.setTexture(tex);
		}
		else if(s=="e")
		{
			tex.loadFromFile("img/dig/rb.png");
			sprite.setTexture(tex);
		}
		else
		{
			tex.loadFromFile("img/player_ship.png");
			sprite.setTexture(tex);
		}

	}
	void move(std::string s)
	{
		float delta_x = 0, delta_y = 0;

		if (sprite.getPosition().y >= 780)
			sprite.setPosition(sprite.getPosition().x, 0);
		else if (sprite.getPosition().y <= 0)
			sprite.setPosition(sprite.getPosition().x, 780);
		if (sprite.getPosition().x >=780)
			sprite.setPosition(0, sprite.getPosition().y);
		else if (sprite.getPosition().x <= 0)
			sprite.setPosition(780, sprite.getPosition().y);

		if (s == "l")
			delta_x = -1;
		else if (s == "r")
			delta_x = 1;
		if (s == "u")
			delta_y = -1;
		else if (s == "d")
			delta_y = 1;

		delta_x *= speed;
		delta_y *= speed;

		sprite.move(delta_x, delta_y);
	}
};
