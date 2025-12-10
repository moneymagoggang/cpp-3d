#include "Tile.h"

Tile::Tile() {
    shape = sf::RectangleShape(sf::Vector2f(130.f, 130.f));
}

Tile::Tile(const sf::Vector2f& position, const GridCoordinate& gridPos, const sf::Texture* texture) {
    shape = sf::RectangleShape(sf::Vector2f(130.f, 130.f));
    shape.setPosition(position);
    shape.setTexture(texture);
    basePosition = position;
    gridPosition = gridPos;
}

void Tile::setPosition(const sf::Vector2f& position) {
    shape.setPosition(position);
}

sf::Vector2f Tile::getPosition() const {
    return shape.getPosition();
}

void Tile::updateOffset(float offsetStep) {
    const float offsetDiff = targetOffset - currentOffset;
    if (offsetDiff != 0) {
        if (offsetDiff > 0) {
            currentOffset += offsetStep;
            shape.setPosition({shape.getPosition().x, shape.getPosition().y + offsetStep});
        } else {
            currentOffset -= offsetStep;
            shape.setPosition({shape.getPosition().x, shape.getPosition().y - offsetStep});
        }
    }
}

bool Tile::needsOffsetUpdate() const {
    return targetOffset != currentOffset;
}

void Tile::setTargetOffset(float offset) {
    targetOffset = offset;
}

float Tile::getTargetOffset() const {
    return targetOffset;
}

float Tile::getCurrentOffset() const {
    return currentOffset;
}

bool Tile::contains(const sf::Vector2f& point) const {
    return shape.getGlobalBounds().contains(point);
}

void Tile::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}
