package Moonstone;

import java.util.*;

//contains components and belongs to systems

public class Entity {

	public int id;
	public Map<String, Component> components = new HashMap<String, Component>();
	
	public Entity(int id) {
		this.id = id;
	}
	
	public String toString() {
		return Integer.toString(id);
	}
	
}
