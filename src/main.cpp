#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {

	sf::Event event;
	sf::Clock clock;
	float elapsedTime;
	
	sf::RenderWindow app(SF::VideoMode(width*scale, height*scale), "moonstone");
	
	app.setVerticalSyncEnabled(true);
	
	while(app.isOpen()) {
	
		while(app.pollEvent(event)) {
			
			if(event.type == sf::Event::Closed) {
				app.close();
			}
			
		}
		
		elapsedTime = clock.restart().asSeconds();
		
		app.clear(sf::Color::Black);
		
		app.display();
	
	}

}