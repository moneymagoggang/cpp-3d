#include "World.h"
#include "iostream"
#include <cstdlib>

World::World() {
    if (!tileTexture.loadFromFile("../assets/textures/tile.png")) {
        std::cerr << "Failed to load tile.png" << std::endl;
    }

    const float rectSize = 80.f;
    const float windowWidth = 800.f;
    const float windowHeight = 600.f;

    const int rows = 10;
    const int cols = 10;

    float mapCenterX = ((cols - 1) - (rows - 1)) * rectSize * 0.5f;
    float mapCenterY = ((cols - 1) + (rows - 1)) * rectSize * 0.5f;

    float offsetX = windowWidth / 2  - mapCenterX;
    float offsetY = windowHeight / 2 - mapCenterY + 500.f;

    for (int y = 0; y < cols; y++) {
        for (int x = 0; x < rows; x++) {
            sf::RectangleShape rect(sf::Vector2f(rectSize, rectSize));
            sf::Vector2f isoPos(
                (x - y) * rectSize * 0.5f,
                (x + y) * rectSize * 0.25f
            );
            isoPos.x += offsetX;
            isoPos.y += offsetY;
            rect.setPosition(isoPos);

            rect.setTexture(&tileTexture);
            // rect.setFillColor(sf::Color::White);

            rectangles.push_back(rect);
        }
    }
}


void World::handleEvent(const sf::Event *event, sf::RenderWindow &window) {
    if (event->is<sf::Event::MouseMoved>() )
    {
        for (auto &r : rectangles)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (r.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                r.setPosition({r.getPosition().x, r.getPosition().y - 10.f});
            }
        }
    }
}


void World::update(float dt, sf::RenderWindow &window) {
    window.clear();

    for (const auto& rect : rectangles) {
        window.draw(rect);
    }

    window.display();
}


sf::Color World::getRandomColor(int seed) {
        int r = rand() % 50;             // от 0 до 49
        int g = 150 + rand() % 105;      // от 150 до 255
        int b = rand() % 50;             // от 0 до 49

        return sf::Color(r, g, b);
}



