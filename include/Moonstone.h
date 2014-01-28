#ifndef MOONSTONE_H_INCLUDED
#define MOONSTONE_H_INCLUDED

#include <vector>

#include "Entity.h"
#include "Component.h"
#include "System.h"

//	base engine class, controls systems, entities, and the MessageCenter
//	adds entities to the correct system when they are given components

class Moonstone {

	public:
		
		std::vector<System*> systems;
		std::vector<Entity*> entities;

};

#endif // MOONSTONE_H_INCLUDED