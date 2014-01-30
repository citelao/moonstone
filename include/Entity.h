#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <map>
#include <string>

#include "Component.h"

typedef int EntityID;

class Entity {

	public:
		EntityID id;
		std::map<std::string, Component*> components;

		Entity(EntityID id);
		virtual std::string ToString();

};

#endif // ENTITY_H
