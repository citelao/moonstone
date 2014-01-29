package Moonstone;

import Moonstone.systems.*;
import Moonstone.components.*;
import java.util.*;
import static java.lang.System.out;

//	base engine class, keeps track of systems, and handles entities

public class Moonstone {
	
	private int entityId = 0;
	
	private Map<String, System> systems = new HashMap<String, System>();
	private Map<Integer, Entity> entities = new HashMap<Integer, Entity>();
	
	//	update systems
	public void Update(float elapsedTime) {
		for(Map.Entry<String, System> systemEntry : systems.entrySet()) {
			System system = systemEntry.getValue();
			system.Update(elapsedTime);
		}
	}
	
	//	add a system to the engine
	public void AddSystem(System sys) {
		systems.put(sys.toString(), sys);
	}
	
	//	remove a system from the engine
	public void RemoveSystem(String sys) {
		systems.remove(sys);
	}
	
	//	creates an entity
	public int SpawnEntity(Component... components) {	
		int id = entityId;
		Entity tempEnt = new Entity(id);
		entities.put(id, tempEnt);
		
		for(Component component : components) {
			entities.get(id).components.put(component.toString(), component);
		}
		
		CheckEntitySystems(id);
		
		entityId++;
		return tempEnt.id;	//	if we want to return the entity as an object
	}
	
	//	removes an entity from all systems and the global entity list
	public void DestroyEntity(int id) {
		for(Map.Entry<String, System> systemEntry : systems.entrySet()) {
			System system = systemEntry.getValue();
			if(system.entities.containsKey(id)) {
				system.entities.remove(id);
			}
		}
		entities.remove(id);
	}
	
	//	attaches a component to an entity
	public void AttachComponent(int id, Component component) {
		entities.get(id).components.put(component.toString(), component);
		CheckEntitySystems(id);
	}
	
	
	//	attaches multiple components to an entity
	public void AttachComponents(int id, Component... components) {
		for(Component component : components) {
			entities.get(id).components.put(component.toString(), component);
		}
		CheckEntitySystems(id);
	}
	
	//	detaches a component from an entity
	public void DetachComponent(int id, String component) {
		if(entities.get(id).components.containsKey(component)) {
			entities.get(id).components.remove(component);
		}
		CheckEntitySystems(id);
	}
	
	//	detaches multiple components from an entity
	public void DetachComponents(int id, String... components) {
		for(String component : components) {
			if(entities.get(id).components.containsKey(component)) {
				entities.get(id).components.remove(component);
			}
		}
		CheckEntitySystems(id);
	}
	
	//	check an entity for what systems it should be in based on its components, and assign it to or remove it from those systems
	public void CheckEntitySystems(int id) {
		
		for(Map.Entry<String, System> systemEntry : systems.entrySet()) {
			System system = systemEntry.getValue();
			boolean fitsSystem = true;
			
			for(String component : system.componentList) {
				if(!entities.get(id).components.containsKey(component)) {
					fitsSystem = false;
				}
			}
			
			if(fitsSystem && !system.entities.containsKey(id)) {
				system.entities.put(id, entities.get(id));
				out.println("entity added to system");
			}
			else if(!fitsSystem && system.entities.containsKey(id)) {
				system.entities.remove(id);
				out.println("entity removed from system");
			}
		}
		
	}
	
	
	public static void main(String[] args) {
		Moonstone engine = new Moonstone();
		
		//	this works! c:
		engine.AddSystem(new RenderSystem());
		
		int test0 = engine.SpawnEntity(new RenderComponent(0f, 0f));
		int test1 = engine.SpawnEntity();
		int test2 = engine.SpawnEntity(new RenderComponent(2f, 7.3f));
		
		engine.DetachComponent(test0, "RenderComponent");
		engine.AttachComponent(test1, new RenderComponent(0f, 4f));
		
		engine.Update(0);
		
		out.println("moonstone terminated");
	}
	
}
