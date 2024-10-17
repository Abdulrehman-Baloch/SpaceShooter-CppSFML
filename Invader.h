#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include"Enemy.h"
class Invader: public Enemy
{
public:
	virtual void Rectangle(Enemy** &E)
		{
			for(int i=0; i<4 ;i++)
				E[2][i].spriteE.setPosition(i*153+80,50);
			for(int i=0;i<4;i++)
				E[1][i].spriteE.setPosition(i*153+100,350);

			E[0][0].spriteE.setPosition(80,150);
			E[0][1].spriteE.setPosition(545,150);
			E[0][2].spriteE.setPosition(80,250);
			E[0][3].spriteE.setPosition(545,250);
		}

	 virtual void Triangle(Enemy** &E)
	 {
		 for(int i=0;i<4;i++)
		 	E[0][i].spriteE.setPosition(360+i*65,i*70);
		 for(int i=0;i<4;i++)
		 	E[1][i].spriteE.setPosition(280-i*65,i*70);
		 for(int i=0;i<4;i++)
			 E[2][i].spriteE.setPosition(90+150*i,320);
	 }

	 virtual void Heart(Enemy** &E)
 {
		E[0][0].spriteE.setPosition(270, 90);
		E[0][1].spriteE.setPosition(400, 90);
		E[0][2].spriteE.setPosition(200, 230);
		E[0][3].spriteE.setPosition(500, 230);
		E[2][0].spriteE.setPosition(335, 160);
		E[2][1].spriteE.setPosition(240,320);
		E[2][2].spriteE.setPosition(470,310);
		E[1][0].spriteE.setPosition(540,130);
		E[1][1].spriteE.setPosition(170,130);
		E[1][2].spriteE.setPosition(290,400);
		E[1][3].spriteE.setPosition(460,400);
		E[2][3].spriteE.setPosition(370,500);

	 }

	 virtual void Cross(Enemy **&E)
	 {
		 for(int i=0;i<4;i++)
		 		E[0][i].spriteE.setPosition(150+i*50,i*70);

		 E[2][0].spriteE.setPosition(360,300);
		 E[2][1].spriteE.setPosition(400,400);

		 E[2][2].spriteE.setPosition(250,300);
		 E[2][3].spriteE.setPosition(200,400);

		 		for(int i=0;i<4;i++)
		 		{

		 				E[1][i].spriteE.setPosition(500-i*60,i*70);
		 		}

	 }
	 virtual void diamond(Enemy **&E){
	 		for(int i=0;i<4;i++)
	 			E[0][i].spriteE.setPosition(340+i*55,i*50);
	 		for(int i=0;i<4;i++)
	 			E[1][i].spriteE.setPosition(290-i*55,i*50);

	 		E[2][0].spriteE.setPosition(160,240);
	 		E[2][1].spriteE.setPosition(240,300);
	 		E[2][2].spriteE.setPosition(460,240);
	 		E[2][3].spriteE.setPosition(380,300);


	 	}
	 virtual void filledRectangle(Enemy **&E)
	 {
	 		for(int i=0;i<2;i++)
	 		{
	 			for(int j=0;j<4;j++)
	 			{
	 				E[i][j].spriteE.setPosition(j*160+120,i*100+120);
	 			}
	 		}
	 		E[2][0].spriteE.setPosition(110,340);
	 		E[2][1].spriteE.setPosition(270,340);
	 		E[2][2].spriteE.setPosition(430,340);
	 		E[2][3].spriteE.setPosition(590,340);
	 }
	 virtual void filledTriangle(Enemy** &E)
	 {
		 for(int i=0;i<4;i++)
		 			E[2][i].spriteE.setPosition(i*80+340,i*60);


		 	 	E[0][1].spriteE.setPosition(240,30);
		 	 	E[0][2].spriteE.setPosition(190,110);
		 	 	E[0][3].spriteE.setPosition(100,200);
		 		E[0][0].spriteE.setPosition(290,120);
		 		E[0][3].spriteE.setPosition(390,120);
		 		for(int i=0;i<4;i++)
		 			E[1][i].spriteE.setPosition(i*80+250,180);
	 }
	 virtual void filledDiamond(Enemy** &E)
	 {
		 for(int i=0;i<3;i++)
		 			E[2][i].spriteE.setPosition(i*110+340,i*80);
		 		for(int i=1;i<3;i++)
		 			E[0][i].spriteE.setPosition(-i*110+340,i*80);
		 		E[0][0].spriteE.setPosition(480,270);
		 		E[0][3].spriteE.setPosition(200,270);
		 		//en[0][4].sprite.setPosition(340+110,3*80);

		 		E[1][0].spriteE.setPosition(340,80);
		 		E[1][1].spriteE.setPosition(340,3*80);

		 		E[1][2].spriteE.setPosition(340-110,2*80);
		 		E[1][3].spriteE.setPosition(340+110,2*80);
		 		//E[1][4].spriteE.setPosition(340,2*80);
	 }


};

class AlphaInvader: public Invader
{
public:
	AlphaInvader()
	{
		texE.loadFromFile("img/enemy_1.png");
		spriteE.setTexture(texE);
	}
};
class BetaInvader: public Invader
{
public:
	BetaInvader()
	{
		texE.loadFromFile("img/enemy_2.png");
		spriteE.setTexture(texE);
	}
};
class  GammaInvader: public Invader
{
public:
	GammaInvader()
	{
		texE.loadFromFile("img/enemy_3.png");
		spriteE.setTexture(texE);
	}
};




