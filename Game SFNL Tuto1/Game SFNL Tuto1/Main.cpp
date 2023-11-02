#include <SFML\Graphics.hpp>
#include <iostream>
#include <SFML\Audio.hpp>

void rectXMove(sf::RectangleShape &rect,int xDis);
void ballMove(sf::CircleShape &ball,int xDis,int yDis);
sf::RectangleShape rectComputer;
sf::RectangleShape rectUser;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600),"SFML Game");
	window.setFramerateLimit(60);
	bool play=true;
	sf::Event event;
	int rectXPosition=0;
	int rectRotation=0;

	sf::Texture image1;
	if(image1.loadFromFile("Data/image1.png")==-1)
	{
		return 1;
	}
	

	
	rectComputer.setSize(sf::Vector2f(100,50));
	rectComputer.setPosition(0,0);
	/*rect.setFillColor(sf::Color::Green);*/
	rectComputer.setTexture(&image1);

	rectUser.setSize(sf::Vector2f(100,50));
	rectUser.setPosition(0,550);
	/*rect.setFillColor(sf::Color::Green);*/
	rectUser.setTexture(&image1);

	sf::CircleShape ball;
	ball.setRadius(5);
	ball.setPosition(0,50);
	ball.setFillColor(sf::Color::Yellow);

	sf::Font font;
	if(font.loadFromFile("Data/OLDENGL_0.TTF")==0)
	{
		return 1;
	}

	sf::Text title;
	title.setFont(font);
	title.setCharacterSize(30);
	title.setString("SFNL Tuto");

	sf::SoundBuffer soundbuf;
	if(soundbuf.loadFromFile("Data/hit.wav")==0)
	{
		return 1;
	}
  sf::Sound sound;
  sound.setBuffer(soundbuf);
 /* sound.setVolume(200);*/
  sound.play();
 /* sound.setLoop(true);*/
  sound.stop();

	while(play==true)
	{
	   //Events
		bool rPressed=false;
		bool rReleased=false;
		bool mousePressed=false;
		bool mouseReleased=false;

		int mouseX=0;int mouseY=0;
		
		while(window.pollEvent(event))
		{
			if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::R)
			{
				/*std::cout<<"Key A has been pressed \n";*/
				rPressed=true;
			}
			if(event.type==sf::Event::KeyReleased && event.key.code==sf::Keyboard::R)
			{
				/*std::cout<<"Key A has been released \n";*/
				rReleased=true;
			}

			if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Right)
			{
				/*std::cout<<"Key Right Arrow has been pressed \n";*/
				/*if(rectXPosition!=(800-rect.getSize().x))
				{
				rectXPosition+=5;
	            rect.setPosition(rectXPosition,0);
					
				}*/
				/*if(rect.getPosition().x!=(800-rect.getSize().x))
				rect.move(5,0);*/
				/*rectXMove(rectComputer,5);*/
				ballMove(ball,5,0);
			}


			if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Left)
			{
				/*std::cout<<"Key A has been pressed \n";*/
				/*if(rectXPosition!=0)
				{
				rectXPosition-=5;
	            rect.setPosition(rectXPosition,0);
					
				}*/
				/*if(rect.getPosition().x!=0)
				rect.move(-5,0);*/
				/*rectXMove(rectComputer,-5);*/
				ballMove(ball,-5,0);
				
			}
			if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Up)
			{
				/*std::cout<<"Key A has been pressed \n";*/
				/*if(rectXPosition!=0)
				{
				rectXPosition-=5;
	            rect.setPosition(rectXPosition,0);
					
				}*/
				/*if(rect.getPosition().x!=0)
				rect.move(-5,0);*/
				/*rectXMove(rectComputer,-5);*/
				ballMove(ball,0,-5);
				
			}
			if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Down)
			{
				/*std::cout<<"Key A has been pressed \n";*/
				/*if(rectXPosition!=0)
				{
				rectXPosition-=5;
	            rect.setPosition(rectXPosition,0);
					
				}*/
				/*if(rect.getPosition().x!=0)
				rect.move(-5,0);*/
				/*rectXMove(rectComputer,-5);*/
				ballMove(ball,0,5);
				
			}

			if(event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
			{
				/*std::cout<<"Key A has been released \n";*/
				mousePressed=true;
			}
			if(event.type==sf::Event::MouseButtonReleased && event.mouseButton.button==sf::Mouse::Left)
			{
				/*std::cout<<"Mouse has been released \n";*/
				mouseReleased=true;
			}
			if(event.type==sf::Event::MouseMoved)
			{
				//std::cout<<"Mouse has been moved \n";

				mouseX=event.mouseButton.x;
				mouseY=event.mouseButton.y;

				/*std::cout<<"Mouse x:"<<mouseX<<" Mouse y:"<<mouseY<<" \n";*/
				/*mouseLeft=true;*/
				//rectXMove(&rectComputer,mouseX);
			}

			if(event.type==sf::Event::Closed)
			{
				play=false;
			}
		}

		 //Logic
		if(rPressed==true)
		{
			/*std::cout<<"Key A has been pressed \n";*/
			rectRotation++;
			rectComputer.setRotation(rectRotation);
			rPressed=false;
		}
		if(rReleased==true)
		{
			std::cout<<"Key A has been released \n";
			rReleased=false;
		}
		if(mousePressed==true)
		{
			mouseX=event.mouseButton.x;
				mouseY=event.mouseButton.y;
			std::cout<<"Mouse  has been clicked " <<"Mouse x:"<<mouseX<<" Mouse y:"<<mouseY<<" \n";
			mousePressed=false;
		}
		if(mouseReleased==true)
		{
			std::cout<<"Mouse  has been Released \n";
			mouseReleased=false;
		}

		/*rectXPosition++;
	    rect.setPosition(rectXPosition,0);*/


	   //Rendering
		window.clear();
		
		window.draw(rectComputer);
		window.draw(rectUser);
		window.draw(ball);
		window.draw(title);
		window.display();
	}

	window.close();
	return 0;
}

void rectXMove(sf::RectangleShape &rect,int xDis)
{
	int XPosition=rect.getPosition().x;
	/*if(XPosition!=(800-rect->getSize().x)&& XPosition!=0)
	{
		rect->move(xDis,0);

		
	}*/
		//rect->move(xDis,0);
	if(XPosition+xDis>=0 &&XPosition+xDis<=700)
	{
		rect.move(xDis,0);
	}
	else
	{
		if(XPosition+xDis<=700)
		xDis++;
		else
        xDis--;
		rectXMove(rect,xDis);
	}

	
	
		
	/*rect->move(xDis,0);*/
	/*std::cout<<"Rectangle  at x:"<<rect.getPosition().x<<"\n";*/
}
void ballMove(sf::CircleShape &ball,int xDis,int yDis)
{
	int XPosition=ball.getPosition().x;
	int YPosition=ball.getPosition().y;
	
	if(XPosition+xDis>=0 &&XPosition+xDis<=793 && YPosition+yDis>=0 &&YPosition+yDis<=593)
	{
		ball.move(xDis,yDis);
	}

	if(ball.getGlobalBounds().intersects(rectComputer.getGlobalBounds())==true)
	{
		ball.move(-xDis,-yDis);
	}
	if(ball.getGlobalBounds().intersects(rectUser.getGlobalBounds())==true)
	{
		ball.move(-xDis,-yDis);
	}
	std::cout<<"Ball  at x:"<<XPosition<<"y:"<<YPosition<<"\n";
}