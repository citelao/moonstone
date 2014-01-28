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
	public Entity SpawnEntity() {	//	we need to figure out a decent way to pass component args to this guy
		Entity tempEnt = new Entity();
		entities.put(entityId, tempEnt);
		return tempEnt;
	}
	
	public void AttachComponent(int id, Component component) {
		entities.get(id).components.put(component.toString(), component);
	}
	
	
	public static void main(String[] args) {
		
	}
	
}
