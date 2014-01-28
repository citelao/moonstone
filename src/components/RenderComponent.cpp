#include "RenderComponent"

RenderComponent::RenderComponent(float xPos, float yPos) {

	x = xPos;
	y = yPos;

}

void RenderComponent::Update(float elapsedTime) {

	for(i_animations = animations.begin(); i_animations != animations.end(); i_animations++) {
		i_animations->second->Update(elapsedTime);
	}

}

void RenderComponent::Draw(sf::RenderWindow *renderWindow) {

	//	need logic to figure out which animaion should be drawn??
	//	like, account for player directions and such to switch animations, etc

}