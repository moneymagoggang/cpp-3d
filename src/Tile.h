
#pragma once
#include <SFML/Graphics.hpp>

struct GridCoordinate {
    int x;
    int y;
};

class Tile {
public:
    Tile();
    Tile(const sf::Vector2f& position, const GridCoordinate& gridPos, sf::Texture* texture, bool accessibleArg = true);

    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;

    void updateOffset(float offsetStep);
    bool needsOffsetUpdate() const;

    void setTargetOffset(float offset);
    float getTargetOffset() const;
    float getCurrentOffset() const;

    bool contains(const sf::Vector2f& point) const;
    void draw(sf::RenderWindow& window) const;

    sf::Vector2f basePosition;
    GridCoordinate gridPosition;
    bool accessible;

    float TILE_SIZE = 130.f;

private:
    sf::RectangleShape shape;
    float currentOffset = 0.f;
    float targetOffset = 0.f;
};
