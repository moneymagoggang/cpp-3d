
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "iostream"


Player::Player(): playerTexture("../assets/textures/farmer.png") {

    if (!playerTexture.loadFromFile("../assets/textures/farmer.png")) {
        std::cerr << "Failed to load tile.png" << std::endl;
    }
    playerShape.setTexture(&playerTexture);
    // playerShape.setPosition({0.f, 0.f});
    // playerShape.setFillColor(sf::Color::Red);
    playerShape.setSize(PLAYER_SIZE);
}

void Player::setGridPosition(Tile tile) {
    if (!tile.accessible) return;
    playerShape.setPosition({tile.basePosition.x + (tile.TILE_SIZE - PLAYER_SIZE.x )  / 2,
                             tile.basePosition.y});
    this->tile = tile;
    tile.accessible =false;
    std::cout << playerShape.getPosition().x << std::endl;
}

void Player::render(sf::RenderWindow &window) {
    window.draw(playerShape);
}
