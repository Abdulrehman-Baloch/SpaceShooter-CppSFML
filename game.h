#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<sstream>
#include <time.h>
#include <iostream>
using namespace std;
#include"menu.h"
#include "player.h"
#include "Bomb.h"
#include"Invader.h"
#include"Monster.h"
#include"Dragon.h"
#include"Laser.h"
#include"FireD.h"
#include"AddOn.h"
const char title[] = "Space Shooter";
using namespace sf;
class Game
{

public:
	Sprite background; // Game background sprite
	Texture bg_texture;


	Menu menu;
	Player *p; // player
	Bullet *b;	//bullet
	Enemy **E;	//Enemy( invaders, monster and dragon)
	Laser* L;
	FireD * F;
	AddOn** A;// AddOns(PowerUp, Fire,
	Bomb *Bo;
	int BombSize;
	int bulletSize;
	int level;
	int RotateB;
	int RotateD;
	int score;
	int wave;
	bool flagMS=false;
	bool flagFire=false;
	bool damage=false;

	Music game;
	Music monster;
	SoundBuffer player;
	Sound shoot;
	SoundBuffer Laser1;
	Sound shootL;




	Game()
	{
		bulletSize=0;
		BombSize=0;
		RotateB=0;
		RotateD=0;
		level=1;
		score=0;
		wave=1;
		Bo=nullptr;


		player.loadFromFile("img2/shoot.wav");
		shoot.setBuffer(player);
		shoot.setVolume(40);

		Laser1.loadFromFile("img2/lazer-reverb-13090.wav");
		shootL.setBuffer(Laser1);
		shootL.setVolume(30);


		game.openFromFile("img2/bruh.wav");
		game.setVolume(35);




		p = new Player("img/player_ship.png" , b);
		bg_texture.loadFromFile("Backgrounds/6.jpeg");
		background.setTexture(bg_texture);
		background.setScale(1, 1);


		E= new Enemy*[5];
		E[0]=new AlphaInvader[4];
		E[1]=new BetaInvader[4];
		E[2]=new GammaInvader[4];
		E[3]=new Monster();
		E[4]=new Dragon();

		L=new Laser(E[3]->spriteE.getPosition().x);
		F=new FireD();

		A=new AddOn*[4];
		A[0]=new PowerUp();
		A[1]=new Fire();
		A[2]=new Life();
		A[3]=new Danger();

	}

	void MakeBullet(int RotateB)
	{
		Bullet obj(p->sprite.getPosition().x,p->sprite.getPosition().y, RotateB);
		Bullet* temp=new Bullet[bulletSize+1];
		for(int i=0;i<bulletSize;i++)
			temp[i]=b[i];
		temp[bulletSize]=obj;
		b=temp;

		bulletSize++;
		p->SizeB++;

	}

	void deleteEnemy()
	{
		int i, j;
		for (i = 0; i < bulletSize; i++)
			for (j = 0; j < 4; j++)
			{
				if (b[i].spriteB.getGlobalBounds().intersects(E[1][j].spriteE.getGlobalBounds()))
				{
					if(flagFire==false)
					{
						deleteBullet(i);
					}
					if(level==1)
					{
						score+=10;
					}
					else if(level==2)
					{
						score+=20;
					}
					else if(level==3)
					{
						score+=30;
					}

					E[1][j].spriteE.setPosition(1000, 0);
					break;
				}
				if (b[i].spriteB.getGlobalBounds().intersects(E[2][j].spriteE.getGlobalBounds()))
				{
					if(flagFire==false)
					{
						deleteBullet(i);
					}
					if (level == 1)
					{
						score += 20;
					}
					else if (level == 2)
					{
						score += 30;
					}
					else if (level == 3)
					{
						score += 40;
					}
					E[2][j].spriteE.setPosition(1000, 0);
					break;
				}
				if (b[i].spriteB.getGlobalBounds().intersects(E[0][j].spriteE.getGlobalBounds()))
				{
					if(flagFire==false)
					{
						deleteBullet(i);
					}
					if (level == 1)
					{
						score += 5;
					}
					else if (level == 2)
					{
						score += 10;
					}
					else if (level == 3)
					{
						score += 15;
					}

					E[0][j].spriteE.setPosition(1000, 0);
					break;
				}
			}
	}

	void destoryPlayer()
	{
		for(int i=0 ; i<4 ; i++)
		{
			if(p->sprite.getGlobalBounds().intersects(E[0][i].spriteE.getGlobalBounds()))
			{
				p->lives--;
				p->sprite.setPosition(350,700);

			}
			if(p->sprite.getGlobalBounds().intersects(E[1][i].spriteE.getGlobalBounds()))
			{

				p->lives--;
				p->sprite.setPosition(350,700);

			}
			if(p->sprite.getGlobalBounds().intersects(E[2][i].spriteE.getGlobalBounds()))
			{
				p->lives--;
				p->sprite.setPosition(350,700);
			}
		}
	}

	void deleteBullet(int index)
	{
		Bullet *temp=new Bullet[bulletSize-1];
		int j=0;
		for(int i=0;i<bulletSize;i++)
		{
			if(i!=index)
			{
				temp[j]=b[i];
				j++;
			}
		}

		b=temp;
		bulletSize--;
		p->SizeB--;
	}


	void OutOfBoundBullet()
	{
		for(int i=0;i<bulletSize;i++)
		{
			if(b[i].spriteB.getPosition().y<=0)
				deleteBullet(i);
			else if(b[i].spriteB.getPosition().x<=0)
				deleteBullet(i);
			else if(b[i].spriteB.getPosition().x>=780)
				deleteBullet(i);
		}
	}


	void waves()
	{
		bool flag=1;
		for(int i=0;i<3;i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if(E[i][j].spriteE.getPosition().x!=1000)
					flag=0;
			}
		}
		if(flag)
		{

			if(level==1)
			{
				wave++;
				if (wave == 2)
				{
					bg_texture.loadFromFile("Backgrounds/2.jpeg");
					E[0][0].Triangle(E);
				}
				if (wave == 3)
				{
					bg_texture.loadFromFile("Backgrounds/1.jpeg");
					E[0][0].Heart(E);
				}
			}
			if(level==2)
			{
				wave++;
				if(wave==1)
				{
					bg_texture.loadFromFile("Backgrounds/10.jpeg");
					E[0][0].diamond(E);
				}
				if(wave==2)
				{
					bg_texture.loadFromFile("Backgrounds/3.jpeg");
					E[0][0].Cross(E);
				}
				if(wave==3)
				{
					bg_texture.loadFromFile("Backgrounds/5.jpeg");
					E[0][0].Rectangle(E);
				}

			}
			if(level==3)
			{
				wave++;
				if(wave==1)
				{
					bg_texture.loadFromFile("Backgrounds/10.jpeg");
					E[0][0].filledRectangle(E);
				}
				if(wave==2)
				{
					bg_texture.loadFromFile("Backgrounds/7.jpeg");
					E[0][0].filledDiamond(E);
				}
				if(wave==3)
				{
					bg_texture.loadFromFile("Backgrounds/6.jpeg");
					E[0][0].filledTriangle(E);
				}

			}

		}
		if (wave == 4) {
			level++;
			wave = 0;
		}


	}

	void MakeBomb(int i,int j)
	{
		Bomb obj(E[i][j].spriteE.getPosition().x,E[i][j].spriteE.getPosition().y);
		Bomb *temp=new Bomb[BombSize+1];
		for(int i=0; i<BombSize ; i++)
			temp[i]=Bo[i];
		temp[BombSize]=obj;
		Bo=temp;
		BombSize++;
	}
	void RandomBomb()
	{
		int i,j;
		i=rand()%3;
		j=rand()%4;
		MakeBomb(i, j);
	}

	void deleteBomb(int index)
	{
		Bomb *temp = new Bomb[BombSize - 1];
		int j = 0;
		for (int i = 0; i < BombSize; i++) {
			if (i != index) {
				temp[j] = Bo[i];
				j++;
			}
		}
		Bo = temp;
		BombSize--;
	}

	void BombDamage()
	{
		for(int i=0; i<BombSize; i++)
		{
			if(Bo[i].spriteBo.getGlobalBounds().intersects(p->sprite.getGlobalBounds()))
			{
				deleteBomb(i);
				p->lives--;
			}
		}
	}

	void MonsterDamage()
	{
		srand(time(0)+rand());
		int i=rand()%700;
		int j=rand()%700;
		if(L->spriteL.getGlobalBounds().intersects(p->sprite.getGlobalBounds()))
		{
			flagMS=true;
			p->lives-=1;
			p->sprite.setPosition(i,j);
		}


	}

	void RotateFire()
	{
		if(RotateD==1)
		{
			F->texF.loadFromFile("img2/fire_-45.png");
			F->tempF.setTexture(F->texF);
			F->spriteF=F->tempF;
			F->spriteF.setPosition(85,E[4]->spriteE.getPosition().y-20);
			F->spriteF.setScale(1,2);

		}
		else if(RotateD==2)
		{
			F->texF.loadFromFile("img2/fire_45.png");
			F->tempF.setTexture(F->texF);
			F->spriteF=F->tempF;
			F->spriteF.setPosition(250,E[4]->spriteE.getPosition().y-20);
			F->spriteF.setScale(1,2);
		}
		else if(RotateD==0)
		{
			F->texF.loadFromFile("img2/fire.png");
			F->spriteF.setTexture(F->texF);
			F->spriteF.setPosition(180,230);
			F->spriteF.setScale(1,2);
		}
	}
	void start_game()
	{
		bool flagM=false;
		menu.display_menu(flagM);
		E[0][0].Rectangle(E);

		game.play();
		srand(time(0));
		RenderWindow window(VideoMode(780, 780), title);
		Clock clock;
		float timer = 0;
		float timer1=0;
		float timer2=0;
		float timer3=0;
		float timer4=0;
		float timer5=0;
		float timer6=0;
		float timer7=0;
		float timerDragMons=0;
		float timerF=0;
		float damageP=0;
		bool flag;
		bool flagPause=false;
		bool flag_for_monster=false;
		bool flag_for_dragon=false;
		bool flagA=false;
		bool flagS=false;
		bool flagOver=false;




		Font font;
		if (!font.loadFromFile("Fonts/Prefectures.ttf")) {
		}


		while (window.isOpen())
		{

			float time = clock.getElapsedTime().asSeconds();
			clock.restart();
			timer += time;
			timer1+=time;
			timer2+=time;
			timer3+=time;
			timerDragMons+=time;


			// cout<<time<<endl;
			Event e;
			while (window.pollEvent(e))
			{
				if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) // If cross/close is clicked/presse
					window.close();
				if(Keyboard::isKeyPressed(Keyboard::Enter) && flagPause == true)
				{
					window.setActive(false);
					menu.display_menu(flagM);
					window.setActive(true);

				}

			}
			if(flagM==true)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Left)) // If left key is pressed
				p->move("l");                        // Player will move to left
			if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
				p->move("r");                       // player will move to right
			if (Keyboard::isKeyPressed(Keyboard::Up))    // If up key is pressed
				p->move("u");                        // player will move upwards
			if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed// player will move downwards
				p->move("d");
			if (Keyboard::isKeyPressed(Keyboard::Space) && flagPause==false) {
				flag = true;
				shoot.play();
			}
			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				if(flagOver==false)
					flagPause=true;
				game.pause();
			}
			if (Keyboard::isKeyPressed(Keyboard::R)){
				flagPause=false;
				game.play();
			}
			if(p->lives==0)
				flagOver=true;
			if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right)) {
				p->rotate("a");
				RotateB = 1;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left)) {
				p->rotate("b");
				RotateB = 2;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left)){
				p->rotate("c");
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right)){
				p->rotate("e");
			}
			else {
				p->rotate("f");
			}


			///////////////////////////////////////////////////     PLAYER AND BULLET			///////////////////////////////////////////////////////////
if(flagOver==false && flagPause==false)
{
			if(!flag_for_dragon && !flag_for_monster)
			{

				if(timerDragMons > 5)
				{

					int n=rand()%10;
					if(n==2)
						flag_for_dragon=1;
					else if(n==1)
						flag_for_monster=1;
					timerDragMons=0;
				}
			}




			if (timer1 > 0.02) {	//// FIRE FOR THE BULLET
				p->fire();
				timer1 = 0;
			}
			if (flag == true && flagA==false )
			{
				if (timer > 0.2) {
					MakeBullet(RotateB);	//// BULLET BEING MADE
					timer = 0;
				}
				flag = false;
			}

			if (flagA == true)	//// FOR POWERUP
			{
				timer7+=time;
				if (timer7 > 0.8)
				{
					shootL.play();
					MakeBullet(1);
					MakeBullet(2);
					MakeBullet(3);
					MakeBullet(4);
					MakeBullet(5);
					MakeBullet(6);
					MakeBullet(7);
					timer7 = 0;
				}
			}
			timer6+=time;
			if(timer6 > 5)
			{
				flagA=false;
				timer6=0;
			}

			///////////////////////////////////////////////////     BOMB		///////////////////////////////////////////////////////////

			if (timer3 > .05) {
				for (int i = 0; i < BombSize; i++)
					Bo[i].spriteBo.move(0, level*0.5);		//// MOVING OF BOMB
			}

			for (int i = 0; i < 4; i++)			//// MOVING AND COLLISION OF ADD ONS WITH SPACESHIP
				A[i]->fall();
			for (int i = 0; i < 4; i++)
				A[i]->collision(*p,p->lives,flagA,flagS,flagFire);

			if(flagS==true)		//// SCORE FOR DODGING DANGER SIGN
			{
				score+=50;
				flagS=false;
			}
			if(flagFire==true)
			{
				timerF+=time;		//// timer for fire ADDON
				if(timerF > 4)
				{
					flagFire=false;
					timerF=0;
				}

			}

			if(p->sprite.getPosition().x >=0 && p->sprite.getPosition(). x < 200)		/// FOR DRAGON FIRE
				RotateD=1;
			else if(p->sprite.getPosition().x > 500 && p->sprite.getPosition().x <= 780)
				RotateD=2;



			OutOfBoundBullet();		//// FOR DELETION OF BULLET OUT OF THE WINDOW
			if(flag_for_monster)
			{
				MonsterDamage();		//// FOR DECREMENT OF LIVE IF LASER COMES IN CONTACT WITH SPACESHIP
			}
			waves();				//// FOR 3 DIFFERENT WAVES
			RotateFire();			//// FOR ROTATING THE FIRE OF THE DRAGON WITH RESPECT TO THE POSITION OF THE PLAYER
			//////////////////////////////////////////////


			window.clear(Color::Black); // clears the screen
			window.draw(background);    // setting background
			window.draw(p->sprite); // setting player on screen

			for(int i=0;i<bulletSize;i++)	//// Bullet being made
				window.draw(b[i].spriteB);



			//// MONSTER ////

				if (flag_for_monster == true)
				{
					timer4 += time;
					if (timer4 > 6)
					{

						flag_for_monster = false;
						timer4 = 0;
						if(flagMS==false)
							score+=100;
						if(wave==0)
							wave++;


					}

					window.draw(E[3]->spriteE);

					E[3]->spriteE.move(E[3]->speedM, 0);
					if (E[3]->spriteE.getPosition().x >= 555
							|| E[3]->spriteE.getPosition().x <= 0)
						E[3]->speedM *= -1;



					window.draw(L->spriteL);
					L->spriteL.move(L->speedL, 0);
					if (L->spriteL.getPosition().x >= 660
							|| L->spriteL.getPosition().x <= 100)
						L->speedL *= -1;
				}



			//// INVADERS AND BOMB  ////

			if (flag_for_monster == false && flag_for_dragon==false)
			{

				deleteEnemy();
				destoryPlayer();
				BombDamage();			//// FOR DECREMENT OF LIVE IF BOMB COMES IN CONTACT WITH SPACESHIP
				for (int i = 0; i < BombSize; i++)
					window.draw(Bo[i].spriteBo);
				for (int i = 0; i < 4; i++)
					window.draw(E[0][i].spriteE);
				for (int i = 0; i < 4; i++)
					window.draw(E[1][i].spriteE);
				for (int i = 0; i < 4; i++)
					window.draw(E[2][i].spriteE);
				if (timer2 > 2) {
					RandomBomb();
					timer2 = 0;
				}
			}


			//// ADD ONS  ////
			window.draw(A[0][0].spriteA);
			window.draw(A[1][0].spriteA);
			window.draw(A[2][0].spriteA);
			window.draw(A[3][0].spriteA);


			//// DRAGON AND FIRE /////

			if(flag_for_dragon)
			{
				timer5+=time;
				if(timer5 > 4)
				{
					flag_for_dragon=false;
					timer5=0;
					if(wave==0)
						wave++;
				}

				window.draw(E[4]->spriteE);
				window.draw(F->spriteF);

			}


}
			Text text("Score :", font, 20);
			text.setPosition(600, 750);

			Text value(to_string(score), font, 20);
			value.setPosition(690, 750);

			Text text1("Wave :", font, 20);
			text1.setPosition(20, 750);

			Text value1(to_string(wave), font, 20);
			value1.setPosition(100, 750);

			Text text2("Lives :", font, 20);
			text2.setPosition(600, 730);

			Text value2(to_string(p->lives), font, 20);
			value2.setPosition(690, 730);

			Text text3("Level :", font, 20);
			text3.setPosition(20, 730);

			Text value3(to_string(level), font, 20);
			value3.setPosition(110, 730);

			Text Pause("Paused\nPress r to\nresume\nPress enter for\nmenu\nPress esc to\nexit", font); //// displaying pause menu
			Pause.setPosition(250, 200);
			Pause.setFillColor(Color::White);
			Pause.setCharacterSize(40);

			Text Power("POWERUP ACTIVATED", font, 30);
			Power.setPosition(250, 600);
			Power.setFillColor(Color::Cyan);
			if(flagA==true )
				window.draw(Power);

			Text Fire("Fire ACTIVATED", font, 30);
			Fire.setPosition(260, 600);
			Fire.setFillColor(Color::Red);
			if(flagFire==true)
				window.draw(Fire);

			RotateB=0;


			if(flagOver)
			{
				game.pause();
				Text over("Game over",font,50);
				over.setPosition(250,300);
				over.setColor(Color::Black);
				window.draw(over);


			}



			window.draw(text);
			window.draw(value);
			window.draw(text1);
			window.draw(value1);
			window.draw(text2);
			window.draw(value2);
			window.draw(text3);
			window.draw(value3);
			if (flagPause == true)
			{
				window.draw(Pause);
			}
			window.display(); // Displying all the sprites
		}
	}

};
