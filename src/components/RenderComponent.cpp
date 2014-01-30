#include <map>
#include <string>

#include "RenderComponent.h"

RenderComponent::RenderComponent(float x, float y) {
    this->x = x;
    this->y = y;
}

std::string RenderComponent::ToString() {
    return "RenderComponent";
}
