
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
    playerShape.setSize({45.f, 60.f});
}

void Player::setGridPosition(Tile tile) {
    playerShape.setPosition(tile.basePosition);
    this->tile = tile;
    std::cout << playerShape.getPosition().x << std::endl;
}

void Player::render(sf::RenderWindow &window) {
    window.draw(playerShape);
}
