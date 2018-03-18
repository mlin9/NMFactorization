#include "environment.h"

//Constructor
Environment::Environment(sf::RenderWindow *window)
{
	screen = window;
}

//Primer
void Environment::start()
{
	mainLoop();
}

//Main Function Loop
void Environment::mainLoop()
{
	
	while(screen->isOpen())
	{
		//Refresh Rendering Window
		init();
	
		//Handle Events
		sf::Event event;
		while(screen -> pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					screen->close();
					break;
					
				//Handle Keys (Pressed)
				case sf::Event::KeyPressed:
					
					switch(event.key.code)
					{	
						case sf::Keyboard::Escape:
							screen->close();
							break;
						case sf::Keyboard::Space:
							break;
						default:
							break;
					}
					break;
					
				default:
					break;
				
				//Handle Keys (Released)
				case sf::Event::KeyReleased:
					
					switch(event.key.code)
					{
						default:
							break;
					}
					break;
			}
		}
		
		//Render Objects
		screen->display();
		screen->setFramerateLimit(60);
	}
}

//Clear Rendering
void Environment::init()
{
	screen->clear();
}
