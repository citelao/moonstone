#include <iostream>
#include <map>
#include <string>

#include <irrlicht.h>

#include "RenderComponent.h"

RenderComponent::RenderComponent(float x, float y, float z, std::string meshLocation, std::string textureLocation, float meshScale) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->meshScale = meshScale;
    this->meshLocation = meshLocation;
    this->textureLocation = textureLocation;
}

std::string RenderComponent::ToString() {
    return "RenderComponent";
}
