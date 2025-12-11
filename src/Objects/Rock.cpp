#include "Rock.h"

#include <iostream>

Rock::Rock() : Object() {
    if (!texture.loadFromFile("../assets/textures/rock.png")) {
        std::cout << "Failed to load rock texture" << std::endl;
    }
    shape.setTexture(&texture);
    shape.setSize(sf::Vector2f(64.f, 64.f));
}

void Rock::render(sf::RenderWindow& window) {
    Object::render(window);
}