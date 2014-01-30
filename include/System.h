#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "Entity.h"
#include "Component.h"

class System {

	public:
		std::map<EntityID, Entity*> entities;
		std::vector<std::string> componentList;

		void Update(float elapsedTime);
		std::string ToString();

};

#endif // SYSTEM_H
