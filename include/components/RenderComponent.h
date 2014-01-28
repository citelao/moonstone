#ifndef RENDERCOMPONENT_H_INCLUDED
#define RENDERCOMPONENT_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>
#include <map>

#include "AnimationSequenceComponent.h"

//	component for containing render data
//	acted on by the render system

class RenderComponent : Component {

	public:
		
		float x, y;
		sf::Sprite sprite;
		
		Render(int xPos, int yPos);
		void Update(float elapsedTime);
		void Draw(sf::RenderWindow *renderWindow);

	private:
	
		std::map<std::string, AnimationSequenceComponent*> animations;
		typedef std::map<std::string, AnimationSequenceComponent*>::iterator i_animations;
		
};

#endif // RENDERCOMPONENT_H_INCLUDED