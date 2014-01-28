#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <map>

#include "Entity.h"
#include "MessageCenter.h"

//	basic system, acts on entities, and their components, contains map of entities within them

class System {
	
	public:
		
		MessageCenter *postman;	//	have Moonstone hand this off to the new system on init
		
		void Update(float elapsedTime);
		void AddEntity(Entity *entity);
		void RemoveEntity(int id);
		
	private:
	
		std::map<int, Entity*> entities;
	
};

#endif // SYSTEM_H_INCLUDED