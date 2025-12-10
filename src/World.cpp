#include "World.h"
#include "iostream"
#include <cstdlib>

World::World() {
   renderTiles();
}

void World::renderTiles() {
    if (!tileTexture.loadFromFile("../assets/textures/tile.png")) {
        std::cerr << "Failed to load tile.png" << std::endl;
    }

    const float rectSize = 80.f;
    const float windowWidth = 800.f;
    const float windowHeight = 600.f;

    const int rows = 50;
    const int cols = 50;

    float mapCenterX = ((cols - 1) - (rows - 1)) * rectSize * 0.5f;
    float mapCenterY = ((cols - 1) + (rows - 1)) * rectSize * 0.5f;

    float offsetX = windowWidth / 2  - mapCenterX;
    float offsetY = windowHeight / 2 - mapCenterY + cols * rows + 700.f;

    for (int y = 0; y < cols; y++) {
        for (int x = 0; x < rows; x++) {
            sf::RectangleShape rect(sf::Vector2f(rectSize, rectSize));

            Tile tile;
            tile.shape = sf::RectangleShape(sf::Vector2f(rectSize, rectSize));
            sf::Vector2f isoPos(
                (x - y) * rectSize * 0.25f,
                (x + y) * rectSize * 0.2f
            );
            isoPos.x += offsetX;
            isoPos.y += offsetY;

            tile.shape.setPosition(isoPos);
            tile.basePosition = isoPos;

            tile.shape.setTexture(&tileTexture);
            // rect.setFillColor(sf::Color::White);

            tiles.push_back(tile);
        }
    }
}


void World::handleEvent(const sf::Event *event, sf::RenderWindow &window) {
    if (event->is<sf::Event::MouseMoved>() )
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        for (auto &t : tiles)
        {
            sf::RectangleShape &r = t.shape;
            if (t.targetOffset == 0.f && r.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                // r.setPosition({r.getPosition().x, r.getPosition().y - OFFSET_HEIGHT});
                t.targetOffset = -OFFSET_HEIGHT;
            }
        }

        lastMousePos = mousePos;
    }
}


void World::update(float dt, sf::RenderWindow &window) {
    // window.clear();
    for (auto& tile : tiles) {
        window.draw(tile.shape);

        if (tile.currentOffset != 0.f && !tile.shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(lastMousePos))) {
            // tile.shape.setPosition(tile.basePosition);
            tile.targetOffset = 0.f;
        }

        const float offsetStep = 0.5f;
        const float offsetDiff = tile.targetOffset - tile.currentOffset;
        if (offsetDiff != 0) {
            if (offsetDiff > 0) {
                tile.currentOffset += offsetStep;
                tile.shape.setPosition({tile.shape.getPosition().x, tile.shape.getPosition().y + offsetStep});
            } else {
                tile.currentOffset -= offsetStep;
                tile.shape.setPosition({tile.shape.getPosition().x, tile.shape.getPosition().y - offsetStep});
            }
        }
    }

    player.render(dt, window);
    // window.display();
}


sf::Color World::getRandomColor(int seed) {
        int r = rand() % 50;             // от 0 до 49
        int g = 150 + rand() % 105;      // от 150 до 255
        int b = rand() % 50;             // от 0 до 49

        return sf::Color(r, g, b);
}



