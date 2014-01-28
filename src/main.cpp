#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "System.h"
#include "RenderSystem.h"

int main() {

	sf::RenderWindow *renderWindow;
	sf::Clock clock;
	sf::Event event;
	float elapsedTime;
	
	RenderSystem renderSystem(512, 256, 2, renderWindow);	//	move to Moonstone class later, have it return the renderWindow
	
	while(renderWindow->isOpen()) {
	
		while(renderWindow->pollEvent(event)) {
			
			if(event.type == sf::Event::Closed) {
				renderWindow->close();
			}
			
		}
		
		elapsedTime = clock.restart().asSeconds();
		
		renderSystem.Update(elapsedTime);	//	draws all of the junk
	
	}

}