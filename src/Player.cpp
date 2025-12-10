
#include <SFML/Graphics.hpp>
#include "Player.h"


Player::Player(): playerTexture("../assets/textures/player.png") {
    // playerShape.setTexture(playerTexture);
    playerShape.setPosition({0.f, 0.f});
    playerShape.setFillColor(sf::Color::Red);
    playerShape.setSize({60.f, 60.f});
}

void Player::render(float dt, sf::RenderWindow &window) {
    window.draw(playerShape);
}
