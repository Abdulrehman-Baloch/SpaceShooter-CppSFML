#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
class AddOn
{
public:
	Texture texA;
	Sprite spriteA;
	int x,y;
	virtual void fall()=0;
	virtual void collision(Player& p,int &l,bool &f,bool &f1,bool &f2)=0;
	//virtual void collision(Player& p)=0;

};

class PowerUp: public AddOn
{
public:
	PowerUp()
	{
		x=100;
		y=-200;
		texA.loadFromFile("img2/energetic.png");
		spriteA.setTexture(texA);
		spriteA.setPosition(x,y);
		spriteA.setScale(1.1,1.1);
	}
	void fall()
	{
		srand(time(0)+rand());
		int random=rand()%800;
		y=spriteA.getPosition().y;
		spriteA.move(0,0.4);
		if(y >= 780)
			spriteA.setPosition(random,-500);
	}
	void collision(Player& p,int &l,bool &f,bool &f1,bool &f2)
	{
		int random=rand()%780;
		if (spriteA.getGlobalBounds().intersects(p.sprite.getGlobalBounds()))
		{
			spriteA.setPosition(random,-500);
			f=true;
		}
	}
};
class Fire: public AddOn
{
public:
	Fire()
	{
		x=200;
		y=-500;
		texA.loadFromFile("img2/flames.png");
		spriteA.setTexture(texA);
		spriteA.setPosition(x,y);
	}

	void fall()
	{
		srand(time(0)+rand());
		int random=rand()%800;
		y=spriteA.getPosition().y;
		spriteA.move(0,0.4);
		if(y >= 780)
			spriteA.setPosition(random,-500);
	}
	void collision(Player& p, int &l,bool &f,bool &f1,bool &f2)
		{
			int random=rand()%780;
			if (spriteA.getGlobalBounds().intersects(p.sprite.getGlobalBounds()))
			{
				spriteA.setPosition(random,-500);
				f2=true;

			}
		}
};
class Life: public AddOn
{
public:
	Life()
	{
		x=500;
		y=-500;
		texA.loadFromFile("img2/love.png");
		spriteA.setTexture(texA);
		spriteA.setPosition(x,y);
		spriteA.setScale(1.5,1.5);
	}
	void fall()
	{
		srand(time(0)+rand());
		int random=rand()%780;
		y=spriteA.getPosition().y;
		spriteA.move(0,0.4);
		if(y >= 780)
			spriteA.setPosition(random,-1000);
	}
	void collision(Player& p,int &l,bool &f,bool &f1,bool &f2)
	{
		int random=rand()%780;
		if (spriteA.getGlobalBounds().intersects(p.sprite.getGlobalBounds()))
		{
			spriteA.setPosition(random,-1500);
			l++;
		}
	}
};
class Danger: public AddOn
{
public:
	Danger()
	{
		x=500;
		y=-1000;
		texA.loadFromFile("img2/sign.png");
		spriteA.setTexture(texA);
		spriteA.setPosition(x,y);
		spriteA.setScale(1.1,1.1);
	}
	void fall()
	{
		srand(time(0)+rand());
		int random=rand()%780;
		y=spriteA.getPosition().y;
		spriteA.move(0,0.4);
		if(y >= 780)
			spriteA.setPosition(random,-1000);
	}
	void collision(Player& p,int &l,bool &f,bool &f1,bool &f2)
	{
		int random=rand()%780;
		if (spriteA.getGlobalBounds().intersects(p.sprite.getGlobalBounds()))
		{
			spriteA.setPosition(random,-500);
			l--;
		}

		else if( this->y>=780)
			f1=true;
	}
};

