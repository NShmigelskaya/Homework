#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

#include "management/RenderManager.h"
#include "management/LogicsManager.h"
#include "management/ParametersManager.h"
#include "storage/DataStorage.h"

#include "instruments/Input.h"
#include "instruments/Time.h"
#include "instruments/Camera.h"

using engine::Renderer2D;
using engine::BoxCollider;
using engine::ParametersBody;
using engine::Script;

namespace engine
{
    class Engine
    {
    public: 

        static Engine* instance();
        ~Engine();

        void run();

        std::unique_ptr<RenderManager> renderManager;
        std::unique_ptr<LogicsManager> logicsManager;
        std::unique_ptr<ParametersManager> parametersManager;
        std::unique_ptr<DataStorage> dataStorage;

    private:
        Engine();

        static Engine* m_instance;
    };
}

namespace engineX
{
    using namespace engine;

    void createObject(std::string name);
    GameObject& getObject(std::string name);
    void deleteObject(std::string name);
    void deleteObject(GameObject* object);

    void runScene();
}

#endif
