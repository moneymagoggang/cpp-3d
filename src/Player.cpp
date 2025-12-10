
#include <SFML/Graphics.hpp>
#include "Player.h"


Player::Player(): playerTexture("../assets/player.png") {
    // playerShape.setTexture(playerTexture);
    playerShape.setPosition(sf::Vector2f(0, 0));
}

void Player::render(float dt, sf::RenderWindow &window) {
    window.draw(playerShape);
}
