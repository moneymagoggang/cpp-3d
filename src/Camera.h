
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>


class Camera {
public:
    Camera();
    // void update(float dt, sf::RenderWindow &window);
    void handleEvent(const sf::Event *event, sf::RenderWindow &window);
    sf::Color getRandomColor(int seed = 256);

private:
};