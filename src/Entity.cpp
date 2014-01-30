#include "Entity.h"

#include <map>
#include <string>
#include <sstream>

#include "Component.h"

Entity::Entity(EntityID id) {
    this->id = id;
}

std::string Entity::ToString() {
    // FIX ME
    return "";
}
