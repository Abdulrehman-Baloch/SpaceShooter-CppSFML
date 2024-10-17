#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
const char titl[] = "MENU";
using namespace sf;
class Menu
{
public:
	Texture menuT;
	Sprite menuS;
	Music sound;
    Menu()
    {

    	menuT.loadFromFile("Backgrounds/9.jpg");
    	menuS.setTexture(menuT);
    	menuS.setScale(1.1,1.9);

    	sound.openFromFile("img2/menuS.wav");
    	sound.play();


    }

    void display_menu(bool &f1)

    {
        RenderWindow window(VideoMode(780, 780), titl);
        bool flagI=false;
        bool flagH=false;
        //bool flagS;
		Font font, font1;
		if (!font.loadFromFile("Fonts/adrenaline_hit/Adrenaline Hit Italic.ttf")) {}
		if (!font1.loadFromFile("Fonts/hertical_sans/Hertical Sans.ttf")) {}
		Text title("SPACE SHOOTER", font, 50);
		title.setPosition(200, 50);


		Text start("START", font, 50);
		start.setPosition(310, 250);


		Text instructions("INSTRUCTIONS", font, 40);
		instructions.setPosition(250, 350);

		Text High("High Scores",font,45);
		High.setPosition(240,440);

		Text exit("EXIT",font,45);
		exit.setPosition(330,540);

		Text roll("22I-1182",font1,15);
		roll.setPosition(10,750);

        while(window.isOpen())
        {
        	Event e1;
			while (window.pollEvent(e1))
			{
				start.setColor(Color::White);
				instructions.setColor(Color::White);
				High.setColor(Color::White);
				exit.setColor(Color::White);
				if (e1.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				{
					window.close();
					f1 = true;
				}
				if (e1.mouseButton.button == Mouse::Left)
				{
					if (Mouse::getPosition(window).x > 300 && Mouse::getPosition(window).x < 480 && Mouse::getPosition(window).y > 200 && Mouse::getPosition(window).y < 300)
					{
						sound.pause();
						window.close();
					}
					if (Mouse::getPosition(window).x > 240 && Mouse::getPosition(window).x < 600 && Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 400)
					{
						flagI = true;
					}
					if(Mouse::getPosition(window).x > 240 && Mouse::getPosition(window).x < 600 && Mouse::getPosition(window).y > 430 && Mouse::getPosition(window).y < 530)
					{
						flagH=true;
					}
					if (Mouse::getPosition(window).x > 330 && Mouse::getPosition(window).x < 400 && Mouse::getPosition(window).y > 530 && Mouse::getPosition(window).y < 600)
					{
						window.close();
						f1=true;
					}

				}
				if (Mouse::getPosition(window).x > 300 && Mouse::getPosition(window).x < 480 && Mouse::getPosition(window).y > 200 && Mouse::getPosition(window).y < 300)
				{
					start.setFillColor(Color::Black);
				}
				if (Mouse::getPosition(window).x > 240 && Mouse::getPosition(window).x < 600 && Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 400)
				{
					instructions.setFillColor(Color::Black);
				}
				if (Mouse::getPosition(window).x > 240 && Mouse::getPosition(window).x < 550 && Mouse::getPosition(window).y > 430 && Mouse::getPosition(window).y < 500)
				{
					High.setFillColor(Color::Black);
				}
				if (Mouse::getPosition(window).x > 240 && Mouse::getPosition(window).x < 500 && Mouse::getPosition(window).y > 530 && Mouse::getPosition(window).y < 600)
				{
					exit.setFillColor(Color::Red);
				}


        	Text inst("INSTRUCTIONS",font,50);
        	inst.setPosition(200,30);
        	Text points("->> MovementKeys = UP,LEFT,RIGHT,DOWN \n\n->> ShootKey = Space \n\n->> Enemies = Invader( Alpha,Beta,Gamma ), Monster, Dragon \n\n++ Shoot the invaders to score \n\n++ Dodge the Monster and Dragon to score \n\n->> AddOn : PowerUp, extra life, Fire, Danger \n\n++ Dodge Danger to score\n\n++ Collect Extra life to gain a life\n\n->> 3 level with 3 waves ",font1,18);
            points.setPosition(20,150);
            Text back("Back",font,50);
            back.setPosition(320,700);
        	if(flagI==true)
        	{
        		window.clear(Color::Black);
        		window.draw(menuS);
        		window.draw(inst);
        		window.draw(points);
        		window.draw(back);
        		if(Mouse::getPosition(window).x > 315 && Mouse::getPosition(window).x < 400 && Mouse::getPosition(window).y > 650 && Mouse::getPosition(window).y < 780)
        			flagI=false;
        	}
        	else
        	{
        		window.clear(Color::Black);
        		window.draw(menuS);
        		window.draw(title);
        		window.draw(start);
        		window.draw(instructions);
        		window.draw(High);
        		window.draw(exit);
        		window.draw(roll);
        	}
        	Text score("LEGENDS",font,50);
        	score.setPosition(250,30);
			Text legends("-> Walter White : 6900\n-> TUCO SALAMACA : 4200 \n-> SAUL GOODMAN : 69420",font1, 45);
			legends.setFillColor(Color::White);
			legends.setPosition(20, 250);
			Text back1("Back", font, 50);
			back1.setPosition(320, 700);
			if(flagH==true)
			{
				window.clear(Color::Black);
				window.draw(menuS);
				window.draw(score);
				window.draw(legends);
				window.draw(back1);
				if(Mouse::getPosition(window).x > 315 && Mouse::getPosition(window).x < 400 && Mouse::getPosition(window).y > 650 && Mouse::getPosition(window).y < 780)
					flagH=false;
			}

        	window.display();
        }
    }

 }

};
