#ifndef ANIMATIONSEQUENCECOMPONENT_H_INCLUDED
#define ANIMATIONSEQUENCECOMPONENT_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

#include "Component.h"

class AnimationSequenceComponent : Component {

    public:
	
        float x, y;         // sprite locations

        int frameCount;     // number of frames
        float frameLength;  // speed of animation

        bool playing = true;

        AnimationSequence(std::string path, int frameNum, float speed);    // path starts at 0, steps up from there
        void Update(float elapsedTime);
        void Draw(sf::RenderWindow *app);
        void Stop();
        void Play();
        void Restart();
        void PlayOnce();    // might use for attacks and the like

    private:

        int currentFrame;   // current position in animation
        float frameTime;    // time on current frame

        std::vector<sf::Texture*> frames;
        sf::Sprite sprite;

};

#endif // ANIMATIONSEQUENCECOMPONENT_H_INCLUDED
