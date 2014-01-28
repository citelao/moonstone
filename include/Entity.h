#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <string>
#include <map>

#include "Component.h"

class Entity {

	public:
	
		int id;
		std::map<std::string, Component*> components;
		
		Entity();
		void AddComponent(Component *component);
		void RemoveComponent(std::string name);	// we should figure out a better way to address components

}

#endif // ENTITY_H_INCLUDED