#include "Engine.h"
#include "iostream"

Engine::Engine(unsigned int width, unsigned int height, const std::string &title)
    : window(sf::VideoMode({width, height}), title) {
}

void Engine::run() {
    sf::Clock clock;
    float lastTime = 0;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            using Scancode = sf::Keyboard::Scancode;
            if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(Scancode::Escape)) window.close();
            world.handleEvent(&(*event), window);
        }
        float dt = clock.restart().asSeconds();

        world.update(dt, window);
    }

}

