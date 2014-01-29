#ifndef SYSTEM_H
#define SYSTEM_H

#include <map>
#include <vector>
#include <string>

#include "Entity.h"
#include "Component.h"

class System {
	
	public:
		std::map<EntityID, Entity*> entities;
		std::vector<String> components;
	
		void Update(float elapsedTime);
		std::string toString();
		
};

#endif // System_H