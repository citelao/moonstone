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
		Draw();
		out.println("updated render system");
	}
	
	public void Draw() {
		//	draw map
		
		//	step through entities and draw those mofos
		for(Map.Entry<Integer, Entity> entityEntry : entities.entrySet()) {
			Entity entity = entityEntry.getValue();
			RenderComponent renderComponent = (RenderComponent)entity.components.get("RenderComponent");
			out.println("draw entity " + entity.toString() + " at " +  String.valueOf(renderComponent.x) + ", " + String.valueOf(renderComponent.y));	//	this would be a draw call if we knew what frickin lib we were using
		}
	}
	
}
