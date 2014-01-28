#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {

	sf::Event event;
	sf::Clock clock;
	float elapsedTime;
	
	sf::RenderWindow renderWindow(SF::VideoMode(width*scale, height*scale), "moonstone");
	
	renderWindow.setVerticalSyncEnabled(true);
	
	while(renderWindow.isOpen()) {
	
		while(renderWindow.pollEvent(event)) {
			
			if(event.type == sf::Event::Closed) {
				renderWindow.close();
			}
			
		}
		
		elapsedTime = clock.restart().asSeconds();
		
		renderWindow.clear(sf::Color::Black);
		
		//	draw your junk here
		
		renderWindow.display();
	
	}

}