package Moonstone;

import java.util.*;

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
	public Entity SpawnEntity(List<Component> components) {
		Entity tempEnt = new Entity(entityId);
		entities.put(entityId, tempEnt);
		
		for(Component component : components) {
			//	map entity to systems in here based off of their components
			entities.get(entityId).components.put(component.toString(), component);
		}
		
		entityId++;
		return tempEnt;
	}
	
	//	attaches a component to an entity
	public void AttachComponent(int id, Component component) {
		entities.get(id).components.put(component.toString(), component);
	}
	
	//	check and entity for what systems it should be in based on its components, and assign it to those systems
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
