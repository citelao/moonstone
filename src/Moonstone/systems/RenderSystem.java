package Moonstone.systems;

import Moonstone.*;
import Moonstone.components.*;
import Moonstone.System;	//	explicitly state because namespace issues

public class RenderSystem extends System {

	public RenderSystem() {
		componentList.add("RenderComponent");
	}
	
	public void Update(float elapsedTime) {
		Draw();
	}
	
	public void Draw() {
		//	draw map
		//	step through entities and draw those mofos
	}
	
}
