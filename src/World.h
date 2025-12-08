
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>


class World {
public:
    World();
    void run();
    void update(float dt, sf::RenderWindow &window);
    void handleEvent(const sf::Event *event, sf::RenderWindow &window);
    sf::Color getRandomColor();

private:
    std::vector<sf::RectangleShape> rectangles;
    float timeout = 0.f;

    sf::Vector2i cursorPos;

};