
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.h"

struct Tile {
    sf::RectangleShape shape;
    sf::Vector2f basePosition;
    float currentOffset = 0.f;
    float targetOffset = 0.f;
};

class World {
public:
    World();
    void update(float dt, sf::RenderWindow &window);
    void handleEvent(const sf::Event *event, sf::RenderWindow &window);
    sf::Color getRandomColor(int seed = 256);

private:
    std::vector<Tile> tiles;
    sf::Texture tileTexture;
    sf::Vector2i lastMousePos;
    float OFFSET_HEIGHT = 10.f;


};