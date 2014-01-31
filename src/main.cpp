#include "Moonstone.h"

int main() {
    Moonstone moonstone;

    moonstone.AddSystem(new RenderSystem);

    EntityID entity1 = moonstone.SpawnEntity();
    EntityID entity2 = moonstone.SpawnEntity(new RenderComponent(14.2, 3));

    moonstone.AttachComponents(entity1, new RenderComponent(0, 0));
    moonstone.DetachComponents(entity2, "RenderComponent");

    moonstone.Update(0.0f);
	return 0;
}
