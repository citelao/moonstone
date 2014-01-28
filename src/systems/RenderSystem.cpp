#include "RenderSystem.h"

RenderSystem::RenderSystem(int w, int h, int s, sf::RenderWindow *window) {

	width = w;
	height = h;
	scale = s;

	window = new sf::RenderWindow(sf::VideoMode(width*scale, height*scale), "moonstone engine");
	renderWindow = window;
	
	camera = new sf::View(sf::FloatRect(0, 0, width, height));
	
	renderWindow.setVerticalSyncEnabled(true);
	renderWindow.setView(camera);

}

RenderSystem::Update(float elapsedTime) {

	renderWindow->clear(sf::Color::Black);
	
	//	entity updates here
	
	renderWindow->display();

}