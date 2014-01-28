#ifndef MOONSTONE_H_INCLUDED
#define MOONSTONE_H_INCLUDED

#include "Entity.h"
#include "Component.h"
#include "System.h"

#include <vector>

class Moonstone {

	public:
		
		std::vector<System*> systems;
		std::vector<Entity*> entities;

};

#endif // MOONSTONE_H_INCLUDED