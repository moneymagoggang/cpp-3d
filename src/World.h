
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

#include "Player.h"
#include "Tile.h"
#include "engine/SoundManager.h"

class World {
public:
    World(sf::RenderWindow &window);
    void update(float dt, sf::RenderWindow &window);
    void handleEvent(const sf::Event *event, sf::RenderWindow &window);
    void renderTiles();
    sf::Color getRandomColor(int seed = 256);

private:
    std::vector<Tile> tiles;
    sf::Texture grassTileTexture;
    sf::Texture waterTileTexture;
    sf::Vector2i lastMousePos;
    float OFFSET_HEIGHT = 10.f;

    int WATER_BORDER = 2;

    Player player;
    SoundManager soundManager;
};
