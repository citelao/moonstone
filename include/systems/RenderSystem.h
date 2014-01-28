#ifndef RENDERSYSTEM_H_INCLUDED
#define RENDERSYSTEM_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "System.h"
#include "Entity.h"
#include "Component.h"
#include "RenderComponent.h"

class RenderSystem : System {

	public:
	
		int height, width, scale;
		sf::RenderWindow *renderWindow;
		sf::View *camera;
		
		RenderSystem(int w, int h, int s, sf::RenderWindow *window);
		void Update(float elapsedTime);	//	seperate draw? no for now.

};

#endif // RENDERSYSTEM_H_INCLUDED