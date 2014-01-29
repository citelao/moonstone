#include "Moonstone.h"

void Moonstone::Update(float elapsedTime) {
	for(auto i_systems : systems) {
		System *system = i_systems.second;
		system->Update(elapsedTime);
	}
}

void AddSystem(System *sys) {
	systems[sys->toString(), sys);
}

void RemoveSystem(String sys) {
	systems.erase(sys);
}
		
EntityID SpawnEntity(std::vector<Component*> components) {
	
}

void DestroyEntity(EntityID id) {
	
}
		
void AttachComponents(EntityID id, Component *component) {
	
}

void AttachComponents(EntityID id, std::vector<Component*> components) {
	
}

void DetachComponents(EntityID id, Component *component) {
	
}

void DetachComponents(EntityID id, std::vector<Component*> components) {
	
}

void CheckEntitySystems(int id) {
	
}
