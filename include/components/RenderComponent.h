#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include <iostream>
#include <map>
#include <string>

#include "Component.h"

class RenderComponent : Component {

	public:
	    float x, y;

	    RenderComponent(float x, float y);
		std::string ToString();

};

#endif // RENDERCOMPONENT_H
