#include "World.h"
#include "iostream"

World::World(unsigned int width, unsigned int height)
    : rect(sf::Vector2f(static_cast<float>(width), static_cast<float>(height))) {
    rect.setFillColor(sf::Color::Green);
    rect.setPosition({50.f, 50.f});
}


void World::update(float dt, sf::RenderWindow &window) {
    window.clear();
    window.draw(rect);
    window.display();
}



