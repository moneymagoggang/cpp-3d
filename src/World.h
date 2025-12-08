
#pragma once
#include <SFML/Graphics.hpp>

class World {
public:
    World(unsigned int width, unsigned int height);
    void run();
    void update(float dt, sf::RenderWindow &window);

private:
    sf::RectangleShape rect;
};