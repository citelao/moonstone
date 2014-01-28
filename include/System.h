#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <map>

#include "Entity.h"

class System {
	
	public:
	
		void Update(float elapsedTime);
		void AddEntity(Entity *entity);
		void RemoveEntity(int id);
		
	private:
	
		std::map<int, Entity*> entities;
	
};

#endif // SYSTEM_H_INCLUDED