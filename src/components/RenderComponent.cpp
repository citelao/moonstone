#include <iostream>
#include <map>
#include <string>

#include <irrlicht.h>

#include "RenderComponent.h"

RenderComponent::RenderComponent(float x, float y, std::string meshLocation, std::string textureLocation) {
    this->x = x;
    this->y = y;
    this->meshLocation = meshLocation;
    this->textureLocation = textureLocation;
}

std::string RenderComponent::ToString() {
    return "RenderComponent";
}
