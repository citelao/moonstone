#include "Entity.h"

#include <iostream>
#include <map>
#include <string>
#include <sstream>

#include "Component.h"

Entity::Entity(EntityID id) {
    this->id = id;
}

std::string Entity::ToString() {
    std::stringstream convert;
    convert << id;
    return convert.str();
}
