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
	public void SpawnEntity(Component... components) {	
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
		CheckEntitySystems(id);
	}
	
	
	//	attaches multiple components to an entity
	public void AttachComponents(int id, Component... components) {
		for(Component component : components) {
			entities.get(id).components.put(component.toString(), component);
		}
		CheckEntitySystems(id);
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
				out.println("entity added to system");
			}
		}
		
	}
	
	
	public static void main(String[] args) {
		Moonstone engine = new Moonstone();
		
		//	this works! c:
		engine.AddSystem(new RenderSystem());
		engine.SpawnEntity(new RenderComponent(0f, 0f));
		engine.SpawnEntity(new RenderComponent(2f, 5f));
		
		engine.Update(0);
		
		out.println("moonstone terminated");
	}
	
}
