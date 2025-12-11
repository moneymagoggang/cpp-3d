#include "Tree.h"

#include <iostream>

Tree::Tree() : Object() {
    if (!texture.loadFromFile("../assets/textures/tree.png")) {
        std::cout << "Failed to load tree texture" << std::endl;
    }
    shape.setTexture(&texture);
    shape.setSize(sf::Vector2f(64.f, 64.f));
}

void Tree::render(sf::RenderWindow& window) {
    Object::render(window);
}