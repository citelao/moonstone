#ifndef MOONSTONE_H_INCLUDED
#define MOONSTONE_H_INCLUDED

#include <vector>
#include <map>

#include "Entity.h"
#include "Component.h"
#include "System.h"

//	base engine class, controls systems, entities, and the MessageCenter
//	adds entities to the correct system when they are given components

class Moonstone {

	public:
		
		int entityID = 0;	//	increments for every created entity
		
		std::vector<System*> systems;
		std::map<int, Entity*> entities;
		
		void Update(float elapsedTime);
		
		void AddSystem(System *sys);
		void RemoveSystem(std::string system);	//	string for system access seems dirty
		
		int SpawnEntity(std::vector<Component*> *components);	//	use argument/message system to pass components, returns id?
		void AttachComponent(int id, Componenet *component);
		void DestroyEntity(int id);

};

#endif // MOONSTONE_H_INCLUDED