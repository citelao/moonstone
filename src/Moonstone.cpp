#include <iostream>

#include "Moonstone.h"

void Moonstone::Update(float elapsedTime) {
	for(auto i_systems : systems) {
		System *system = i_systems.second;
		system->Update(elapsedTime);
		//system->Update(elapsedTime);
	}
}

void Moonstone::AddSystem(System *sys) {
	systems[sys->ToString()] = sys;
	std::cout << sys->ToString() << " added" << std::endl;
}

void Moonstone::RemoveSystem(std::string sys) {
	systems.erase(sys);
	std::cout << sys << " removed" << std::endl;
}

EntityID Moonstone::SpawnEntity() {
    EntityID id = nextID;
    Entity *tempEnt = new Entity(id);
    entities[id] = tempEnt;

    nextID++;
    return id;
}

EntityID Moonstone::SpawnEntity(Component *component) {
    EntityID id = nextID;
    Entity *tempEnt = new Entity(id);
    entities[id] = tempEnt;

    entities[id]->components[component->ToString()] = component;

	CheckEntitySystems(id);

	nextID++;
	return id;
}

EntityID Moonstone::SpawnEntity(std::vector<Component*> components) {
    EntityID id = nextID;
    Entity *tempEnt = new Entity(id);
    entities[id] = tempEnt;

	for(auto component : components) {
        entities[id]->components[component->ToString()] = component;
	}

	CheckEntitySystems(id);

	nextID++;
	return id;
}

void Moonstone::DestroyEntity(EntityID id) {
    for(auto i_systems : systems) {
        System *system = i_systems.second;
        if(system->entities.count(id)) {
            system->entities.erase(id);
        }
    }
    entities.erase(id);
}

void Moonstone::AttachComponents(EntityID id, Component *component) {
    entities[id]->components[component->ToString()] = component;
    CheckEntitySystems(id);
}

void Moonstone::AttachComponents(EntityID id, std::vector<Component*> components) {
    for(Component *component : components) {
        entities[id]->components[component->ToString()] = component;
    }
    CheckEntitySystems(id);
}

void Moonstone::DetachComponents(EntityID id, std::string component) {
    if(entities[id]->components.count(component)) {
        entities[id]->components.erase(component);
    }
    CheckEntitySystems(id);
}

void Moonstone::DetachComponents(EntityID id, std::vector<std::string> components) {
    for(std::string component : components) {
        if(entities[id]->components.count(component)) {
            entities[id]->components.erase(component);
        }
    }
    CheckEntitySystems(id);
}

void Moonstone::CheckEntitySystems(EntityID id) {

    for(auto i_systems : systems) {
        System *system = i_systems.second;
        bool fitsSystem = true;

        for(auto component : system->componentList) {
            if(!entities[id]->components.count(component)) {
                fitsSystem = false;
            }
        }

        if(fitsSystem && !system->entities.count(id)) {
            system->entities[id] = entities[id];
            std::cout << id << " added to " << system->ToString() << std::endl;
        }
        else if(!fitsSystem && system->entities.count(id)) {
            system->entities.erase(id);
            std::cout << id << " removed from " << system->ToString() << std::endl;
        }
    }

}
