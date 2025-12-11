#include "Object.h"
#include "../Tile.h"

#include <iostream>

Object::Object() {
    shape.setSize(OBJECT_SIZE);
}

void Object::setGridPosition(Tile tile) {
    if (!tile.accessible) {
        std::cout << "Object does not have an accessible tile." << std::endl;
        return;
    };
    shape.setPosition({tile.basePosition.x + (tile.TILE_SIZE - OBJECT_SIZE.x) / 2,
                           tile.basePosition.y});
    this->tile = tile;
    tile.accessible = false;
}


void Object::render(sf::RenderWindow& window) {
    window.draw(shape);
}