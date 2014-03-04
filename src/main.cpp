#include "Moonstone.h"
#include "messaging/Any.h"

void observer(std::vector<Any> unused)
{
    std::cout << "callback" << std::endl;
}

int main() {
    Moonstone moonstone;
    MessageCenter postman;
    
    std::vector<Any> args = std::vector<Any>();
    args.push_back(new Any());
    
    postman.registerObserver("eventname", observer);
//    postman.notify("eventname", args);
//    postman.notify("eventname", args);
//    postman.notify("noresponse", args);
    
//    
//    moonstone.AddSystem(new RenderSystem);
//
//    EntityID entity1 = moonstone.SpawnEntity();
//    EntityID entity2 = moonstone.SpawnEntity(new RenderComponent(14.2, 3));
//    
//    std::vector<Component*> test(2, new RenderComponent(14.2, 3));
//    EntityID entity3 = moonstone.SpawnEntity(test);
//
//    moonstone.AttachComponents(entity1, new RenderComponent(0, 0));
//    moonstone.DetachComponents(entity2, "RenderComponent");
//    
//    moonstone.Update(0.0f);
	return 0;
}
