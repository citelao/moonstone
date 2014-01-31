#include <iostream>

#include "RenderSystem.h"
#include "RenderComponent.h"

RenderSystem::RenderSystem() {
    componentList.push_back("RenderComponent");
}

void RenderSystem::Update(float elapsedTime) {
    for(auto i_entities : entities) {
        Entity *entity = i_entities.second;
        RenderComponent *renderComponent = (RenderComponent*)entity->components["RenderComponent"];
        std::cout << entity->id << " was updated at (" << renderComponent->x << ", " << renderComponent->y << ")" << std::endl;
    }
}

std::string RenderSystem::ToString() {
    return "RenderSystem";  // find better way goddang
}
