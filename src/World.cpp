#include "World.h"
#include "iostream"
#include <cstdlib>

World::World(sf::RenderWindow &window) {
   renderTiles();
    player.setGridPosition(tiles[20]);
}

void World::renderTiles() {
    if (!tileTexture.loadFromFile("../assets/textures/tile2.png")) {
        std::cerr << "Failed to load tile.png" << std::endl;
    }

    const float rectSize = 130.f;
    const float windowWidth = 800.f;
    const float windowHeight = 600.f;

    const int rows = 6;
    const int cols = 6;

    // float mapCenterX = ((cols - 1) - (rows - 1)) * rectSize * 0.5f;
    // float mapCenterY = ((cols - 1) + (rows - 1)) * rectSize * 0.5f - 1300.f;
    //
    float offsetX = (rows * rectSize) / 2;
    // float offsetY = windowHeight / 2 - mapCenterY + cols * rows;

    for (int y = 0; y < cols; y++) {
        for (int x = 0; x < rows; x++) {
            sf::Vector2f isoPos(
                (x - y) * rectSize * 0.5f,
                (x + y) * rectSize * 0.25f
            );
            // isoPos.x -= (rectSize * 0.5f) - offsetX;
            // isoPos.y += offsetY;

            GridCoordinate gridPos = { x, y };
            Tile tile(isoPos, gridPos, &tileTexture);

            tiles.push_back(tile);
        }
    }
}


void World::handleEvent(const sf::Event *event, sf::RenderWindow &window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (event->is<sf::Event::MouseMoved>() )
    {
        const float x = mousePos.x;
        const float y = mousePos.y;

        sf::Vector2i gridPos(
            (int)(-130.f * 0.25f * x - 130.f * 0.5f * y) / (-130.f * 0.5f * 130.f * 0.25f - 130.f * 0.5f * 130.f * 0.25f),
            (int)(130.f * 0.25f * x - 130.f * 0.5f * y) / (-130.f * 0.5f * 130.f * 0.25f - 130.f * 0.5f * 130.f * 0.25f)
        );


        for (auto &t : tiles)
        {
            if (t.gridPosition.x == gridPos.x && t.gridPosition.y == gridPos.y) {
                std::cout << "Tale " + std::to_string(t.gridPosition.x) + " " + std::to_string(t.gridPosition.y) + " hovered" << std::endl;
                t.setTargetOffset(-OFFSET_HEIGHT);
            }

            // std::cout << x << std::endl;
            // std::cout << y << std::endl;
            // std::cout << gridPos.x << std::endl;
            // std::cout << gridPos.y << std::endl;
            // std::cout << t.gridPosition.x << std::endl;
        }

        lastMousePos = mousePos;
    }

    // if (event->is<sf::Event::MouseButtonReleased>() )
    // {
    //     std::cout << "Mouse pressed" << std::endl;
    //     for (auto &t : tiles)
    //     {
    //         if (t.contains(static_cast<sf::Vector2f>(mousePos))) {
    //             std::cout << "Tile pressed" << std::endl;
    //             player.setGridPosition(t);
    //         }
    //     }
    //
    //     lastMousePos = mousePos;
    // }
}


void World::update(float dt, sf::RenderWindow &window) {
    // window.clear();
    const float x = lastMousePos.x;
    const float y = lastMousePos.y;

    sf::Vector2i gridPos(
        (int)(-130.f * 0.25f * x - 130.f * 0.5f * y) / (-130.f * 0.5f * 130.f * 0.25f - 130.f * 0.5f * 130.f * 0.25f),
        (int)(130.f * 0.25f * x - 130.f * 0.5f * y) / (-130.f * 0.5f * 130.f * 0.25f - 130.f * 0.5f * 130.f * 0.25f)
    );

    for (auto& tile : tiles) {
        tile.draw(window);

        // if (tile.getCurrentOffset() != 0.f && !tile.contains(static_cast<sf::Vector2f>(lastMousePos))) {
        //     tile.setTargetOffset(0.f);
        // }

        if (tile.gridPosition.x != gridPos.x || tile.gridPosition.y != gridPos.y) {
            tile.setTargetOffset(0.f);
        }

        const float offsetStep = 0.5f;
        if (tile.needsOffsetUpdate()) {
            tile.updateOffset(offsetStep);
        }
    }

    player.render(window);

    // window.display();
}


sf::Color World::getRandomColor(int seed) {
        int r = rand() % 50;             // от 0 до 49
        int g = 150 + rand() % 105;      // от 150 до 255
        int b = rand() % 50;             // от 0 до 49

        return sf::Color(r, g, b);
}



