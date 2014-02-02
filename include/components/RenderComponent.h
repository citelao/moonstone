#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include <irrlicht.h>

#include <iostream>
#include <map>
#include <string>

#include "Component.h"

class RenderComponent : public Component {

	public:
	    float x, y, z;
	    float meshScale;
        irr::scene::IAnimatedMesh *mesh;
        std::string meshLocation;
        std::string textureLocation;
        irr::scene::IAnimatedMeshSceneNode *sceneNode;

	    RenderComponent(float x, float y, float z, std::string meshLocation, std::string textureLocation, float meshScale = 1);
		std::string ToString();

};

#endif // RENDERCOMPONENT_H
