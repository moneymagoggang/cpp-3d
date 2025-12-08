
#pragma once
#include <SFML/Graphics.hpp>

class Engine {
public:
    Engine(unsigned int width, unsigned int height, const std::string& title);
    void run();

private:
    sf::RenderWindow window;
};