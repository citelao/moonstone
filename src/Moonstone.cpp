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
}

void Moonstone::RemoveSystem(std::string sys) {
	systems.erase(sys);
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
    entities.erase(id);

}

void Moonstone::AttachComponents(EntityID id, Component *component) {

}

void Moonstone::AttachComponents(EntityID id, std::vector<Component*> components) {

}

void Moonstone::DetachComponents(EntityID id, Component *component) {

}

void Moonstone::DetachComponents(EntityID id, std::vector<Component*> components) {

}

void Moonstone::CheckEntitySystems(EntityID id) {

}
