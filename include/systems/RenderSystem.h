#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <map>
#include <vector>
#include <string>

#include "Entity.h"
#include "Component.h"
#include "System.h"

#include "RenderComponent.h"

class RenderSystem : System {

    public:
        RenderSystem();
        void Update(float elapsedTime);
        std::string ToString();

    private:
        void Draw();

};

#endif // RENDERSYSTEM_H
