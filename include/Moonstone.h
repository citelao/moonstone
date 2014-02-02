#ifndef MOONSTONE_H
#define MOONSTONE_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "System.h"
#include "Entity.h"
#include "Component.h"

#include "RenderSystem.h"
#include "RenderComponent.h"

class Moonstone {

	public:
	    bool isRunning = true;

		void Update(float elapsedTime);

		void AddSystem(System *sys);
		void RemoveSystem(std::string sys);

        EntityID SpawnEntity();
        EntityID SpawnEntity(Component *components);
		EntityID SpawnEntity(std::vector<Component*> components);
		void DestroyEntity(EntityID id);

		void AttachComponents(EntityID id, Component *component);
		void AttachComponents(EntityID id, std::vector<Component*> components);
		void DetachComponents(EntityID id, std::string component);
		void DetachComponents(EntityID id, std::vector<std::string> components);

		System* GetSystem(std::string sys);
		Entity* GetEntity(EntityID id);

	private:
		EntityID nextID = 0;
		std::map<std::string, System*> systems;
		std::map<EntityID, Entity*> entities;

		void CheckEntitySystems(EntityID id);

};

#endif // MOONSTONE_H
