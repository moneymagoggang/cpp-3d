#include "World.h"
#include "iostream"
#include <cstdlib>

World::World() {
    const float rectSize = 30.f;
    const float spacing = 0.f;

    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            sf::RectangleShape rect(sf::Vector2f(rectSize, rectSize));
            rect.setPosition({x * (rectSize + spacing) + 50.f, y * (rectSize + spacing) + 50.f});

            rect.setFillColor(getRandomColor());

            rectangles.push_back(rect);
        }
    }
}


void World::handleEvent(const sf::Event *event, sf::RenderWindow &window) {
    if (event->is<sf::Event::MouseMoved>() )
    {
        cursorPos = sf::Mouse::getPosition(window);

        std::cout << "Position of cursor: " << cursorPos.x << "," << cursorPos.y << std::endl;
    }
}


void World::update(float dt, sf::RenderWindow &window) {
    window.clear();

    bool isHovering = false;
    for (auto& rect : rectangles) {
        if (rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(cursorPos))) {
            isHovering = true;
            if (timeout >= 0.2f) {
                timeout = 0.f;
                rect.setFillColor(getRandomColor());
            }
        }
    }

    if (isHovering) {
        timeout += dt;
    } else {
        timeout = 0.f;
    }

    for (const auto& rect : rectangles) {
        window.draw(rect);
    }

    window.display();
}


sf::Color World::getRandomColor() {
    return sf::Color(
        rand() % 256,
        rand() % 256,
        rand() % 256
    );
}



