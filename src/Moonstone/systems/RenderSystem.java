package Moonstone.systems;

import java.util.Map;

import Moonstone.*;
import Moonstone.components.*;
import Moonstone.System;	//	explicitly state because namespace issues
import static java.lang.System.out;

public class RenderSystem extends System {

	public RenderSystem() {
		componentList.add("RenderComponent");
	}
	
	public void Update(float elapsedTime) {
		
		for(Map.Entry<Integer, Entity> entityEntry : entities.entrySet()) {
			Entity entity = entityEntry.getValue();
			out.println(entity.toString());
		}
		
		out.println("updated render system");
		
		Draw();
	}
	
	public void Draw() {
		//	draw map
		//	step through entities and draw those mofos
	}
	
}
