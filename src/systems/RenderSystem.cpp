#include <iostream>

#include "RenderSystem.h"
#include "RenderComponent.h"

RenderSystem::RenderSystem() {

    componentList.push_back("RenderComponent");

    device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, 0);

    videoDriver = device->getVideoDriver();
    sceneManager = device->getSceneManager();
    guiEnvironment = device->getGUIEnvironment();

    camera = sceneManager->addCameraSceneNode(0, irr::core::vector3df(0,30,-40), irr::core::vector3df(0,5,0));

}

void RenderSystem::AddEntity(Entity *entity) {

    entities[entity->id] = entity;
    RenderComponent *renderComponent = (RenderComponent*)entity->components["RenderComponent"];

    renderComponent->mesh = sceneManager->getMesh(renderComponent->meshLocation.c_str());
    renderComponent->sceneNode = sceneManager->addAnimatedMeshSceneNode(renderComponent->mesh);

    if(renderComponent->sceneNode) {
        renderComponent->sceneNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        renderComponent->sceneNode->setMD2Animation(irr::scene::EMAT_STAND);
        renderComponent->sceneNode->setMaterialTexture(0, videoDriver->getTexture(renderComponent->textureLocation.c_str()));
    }

}

void RenderSystem::Update(float elapsedTime) {

    if(device->run()) {
        Draw();
    }

    //for(auto i_entities : entities) {
    //    Entity *entity = i_entities.second;
    //    RenderComponent *renderComponent = (RenderComponent*)entity->components["RenderComponent"];
    //    std::cout << entity->id << " was updated at (" << renderComponent->x << ", " << renderComponent->y << ")" << std::endl;
    //}
}

void RenderSystem::Draw() {

    videoDriver->beginScene(true, true, irr::video::SColor(255,100,101,140));

    sceneManager->drawAll();
    guiEnvironment->drawAll();

    videoDriver->endScene();

}

std::string RenderSystem::ToString() {
    return "RenderSystem";  // find better way goddang
}
