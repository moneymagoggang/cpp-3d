#include "Engine.h"
#include "iostream"


Engine::Engine(unsigned int width, unsigned int height, const std::string &title)
    : window(sf::VideoMode({width, height}), title) {
    ImGui::SFML::Init(window);
}

void Engine::run() {
    sf::Clock clock;
    sf::Clock deltaClock;
    float lastTime = 0;
    // bool dragging = false;
    sf::View view = window.getDefaultView();
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            using Scancode = sf::Keyboard::Scancode;
            ImGui::SFML::ProcessEvent(window, *event);
            if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(Scancode::Escape)) window.close();
            world.handleEvent(&(*event), window);

        }

        ImGui::SFML::Update(window, deltaClock.restart());

        float dt = clock.restart().asSeconds();

        // ImGui controls
        ImGui::Begin("Engine Controls");
        ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
        ImGui::Separator();

        if (ImGui::Button("Reset View")) {
            view = window.getDefaultView();
        }

        static bool showGrid = false;
        ImGui::Checkbox("Show Grid", &showGrid);

        static float zoomLevel = 1.0f;
        if (ImGui::SliderFloat("Zoom", &zoomLevel, 0.1f, 5.0f)) {
            view.setSize(window.getDefaultView().getSize() / zoomLevel);
        }


        ImGui::Separator();
        ImGui::Text("World Info");
        ImGui::Text("Delta Time: %.3f ms", dt * 1000.0f);

        ImGui::End();

        window.clear();

        window.setView(view);

        world.update(dt, window);

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}

