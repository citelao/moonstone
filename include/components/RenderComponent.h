#ifndef RENDERCOMPONENT_H_INCLUDED
#define RENDERCOMPONENT_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "AnimationSequenceComponent"

#include <vector>
#include <string>
#include <map>

class Render : Component {

	public:
		
		float x, y;
		sf::Sprite sprite;
		
		Render(int xPos, int yPos);
		void Update(float elapsedTime);
		void Draw(sf::RenderWindow *app);

	private:
	
		std::map<std::string, AnimationSequenceComponent*> animations;
        typedef std::map<std::string, AnimationSequenceComponent*>::iterator i_animations;
		
};

#endif // RENDER_H_INCLUDED