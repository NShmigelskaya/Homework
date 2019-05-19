#ifndef DATASTORAGE_H
#define DATASTORAGE_H
#include <SFML/Graphics.hpp>
#include <fstream>

namespace engine
{
    
    class DataStorage
    {
    public:
        std::map<std::string, GameObject*> gameObjects;

    private:
        DataStorage();

    };
}

#endif
