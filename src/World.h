
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.h"
#include "Tile.h"

class World {
public:
    World(sf::RenderWindow &window);
    void update(float dt, sf::RenderWindow &window);
    void handleEvent(const sf::Event *event, sf::RenderWindow &window);
    void renderTiles();
    sf::Color getRandomColor(int seed = 256);

private:
    std::vector<Tile> tiles;
    sf::Texture tileTexture;
    sf::Vector2i lastMousePos;
    float OFFSET_HEIGHT = 10.f;

    Player player;
};