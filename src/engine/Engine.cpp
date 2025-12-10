#include "Engine.h"
#include "iostream"


Engine::Engine(unsigned int width, unsigned int height, const std::string &title)
    : window(sf::VideoMode({width, height}), title), debug(window), world(window), texture("../assets/textures/background.png") ,sprite(texture) {
}

void Engine::run() {
    sf::Clock clock;
    sf::Clock deltaClock;
    float lastTime = 0;
    // bool dragging = false;
    sf::View view = window.getDefaultView();
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            using Scancode = sf::Keyboard::Scancode;
            ImGui::SFML::ProcessEvent(window, *event);
            if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(Scancode::Escape)) window.close();
            world.handleEvent(&(*event), window);

        }

        ImGui::SFML::Update(window, deltaClock.restart());

        float dt = clock.restart().asSeconds();

        window.clear();

        window.setView(window.getDefaultView());
        window.draw(sprite);

        window.setView(view);

        world.update(dt, window);

        debug.render(dt, window, view);

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}

