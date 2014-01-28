package Moonstone;

import java.util.*;

//basic system, acts on entities, and their components, contains map of entities within them

public class System {

	public Map<Integer, Entity> entities = new HashMap<Integer, Entity>();
	public List<String> componentList = new ArrayList<String>(); //	list of components required for an entity to be a member of this system
	
	public System() {
		
	}
	
	//	update entities in the system
	public void Update(float elapsedTime) {
		
	}
	
	public String toString() {
		return this.getClass().getSimpleName();
	}
	
}
