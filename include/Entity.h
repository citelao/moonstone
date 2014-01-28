#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <string>
#include <map>

#include "Component.h"

//	contains components and belongs to systems

class Entity {

	public:
	
		int id;
		std::map<std::string, Component*> components;
		
		Entity(int idNum);
		
		void AddComponent(Component *component);
		void RemoveComponent(std::string name);	// we should figure out a better way to address components

};

Entity::Entity(int idNum) {
	id = idNum;
}

#endif // ENTITY_H_INCLUDED