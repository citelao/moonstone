#ifndef MOONSTONE_H
#define MOONSTONE_H

#include <vector>
#include <map>
#include <string>

#include "System.h"
#include "Entity.h"
#include "Component.h"

class Moonstone {

	public:
		void Update(float elapsedTime);
		
		void AddSystem(System *sys);
		void RemoveSystem(String sys);
		
		EntityID SpawnEntity(std::vector<Component*> components);
		void DestroyEntity(EntityID id);
		
		void AttachComponents(EntityID id, Component *component);
		void AttachComponents(EntityID id, std::vector<Component*> components);
		void DetachComponents(EntityID id, Component *component);
		void DetachComponents(EntityID id, std::vector<Component*> components);
				
	private:
		EntityID nextID = 0;
		std::map<std::string, System*> systems;
		std::map<EntityID, Entity*> entities;
		
		void CheckEntitySystems(int id);
		
};

#endif // MOONSTONE_H