package Moonstone;

import java.util.*;
import Moonstone.systems.*;

//	base engine class, keeps track of systems, and handles entities

public class Moonstone {
	
	private int entityId = 0;
	
	private Map<String, System> systems = new HashMap<String, System>();
	private Map<Integer, Entity> entities = new HashMap<Integer, Entity>();
	
	//	add a system to the engine
	public void AddSystem(System sys) {
		systems.put(sys.toString(), sys);
	}
	
	//	remove a system from the engine
	public void RemoveSystem(String sys) {
		systems.remove(sys);
	}
	
	//	creates an entity
	public void SpawnEntity(List<Component> components) {
		int id = entityId;
		Entity tempEnt = new Entity(id);
		entities.put(id, tempEnt);
		
		for(Component component : components) {
			entities.get(id).components.put(component.toString(), component);
		}
		
		CheckEntitySystems(id);
		
		entityId++;
		//return tempEnt;	//	if we want to return the entity as an object
	}
	
	//	attaches a component to an entity
	public void AttachComponent(int id, Component component) {
		entities.get(id).components.put(component.toString(), component);
	}
	
	
	//	attaches multiple components to an entity
	public void AttachComponents(int id, List<Component> components) {
		for(Component component : components) {
			entities.get(id).components.put(component.toString(), component);
		}
	}
	
	//	check an entity for what systems it should be in based on its components, and assign it to those systems
	public void CheckEntitySystems(int id) {
		
		for(Map.Entry<String, System> systemEntry : systems.entrySet()) {
			System system = systemEntry.getValue();
			boolean inSystem = true;
			
			for(Map.Entry<String, Component> componentEntry : entities.get(id).components.entrySet()) {
				Component component = componentEntry.getValue();
				if(!system.componentList.contains(component.toString())) {
					inSystem = false;
				}
			}
			
			if(inSystem) {
				system.entities.put(id, entities.get(id));
			}
		}
		
	}
	
	
	public static void main(String[] args) {
		
	}
	
}
