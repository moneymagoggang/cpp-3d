
#pragma once
#include <SFML/Graphics.hpp>

#include "Debug.h"
#include "../World.h"

class Engine {
public:
    Engine(unsigned int width, unsigned int height, const std::string& title);
    void run();

private:
    sf::RenderWindow window;
    sf::Texture texture;
    sf::Sprite sprite;

    Debug debug;

    World world;
};
