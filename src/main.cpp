#include "Moonstone.h"

int main() {
    Moonstone moonstone;

    moonstone.AddSystem(new RenderSystem);

    EntityID entity1 = moonstone.SpawnEntity();
    //EntityID entity2 = moonstone.SpawnEntity(new RenderComponent(14.2, 3));

    moonstone.AttachComponents(entity1, new RenderComponent(0, 0, 0, "media/sydney.md2", "media/sydney.bmp", 0.08));
    //moonstone.DetachComponents(entity2, "RenderComponent");

    while(moonstone.isRunning) {
        moonstone.Update(0.0f);
    }

    return 0;
}
