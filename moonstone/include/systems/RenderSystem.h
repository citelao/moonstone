#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <irrlicht.h>

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "Entity.h"
#include "Component.h"
#include "System.h"

#include "RenderComponent.h"

class RenderSystem : public System {

    public:
        RenderSystem();
        void AddEntity(Entity *entity);
        void Update(float elapsedTime);
        std::string ToString();

    private:
        irr::IrrlichtDevice *device;

        irr::video::IVideoDriver *videoDriver;
        irr::scene::ISceneManager *sceneManager;
        irr::gui::IGUIEnvironment *guiEnvironment;

        irr::scene::ICameraSceneNode *camera;

        void Draw();

};

#endif // RENDERSYSTEM_H
