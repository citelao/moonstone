#include <iostream>
#include <string>

#include "System.h"

void System::Update(float elapsedTime) {
}

void System::AddEntity(Entity *entity) {
    entities[entity->id] = entity;
}

void System::RemoveEntity(EntityID id) {
    entities.erase(id);
}

std::string System::ToString() {
    return "System"; // frick this shiz find a better frickin way
}
