
#include <SFML/Graphics.hpp>
#include "Debug.h"


Debug::Debug(sf::RenderWindow &window) {
    ImGui::SFML::Init(window);
}

void Debug::render(float dt, sf::RenderWindow &window, sf::View &view) {
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
    ImGui::Text("Cursor Position: X: %.1f, Y: %.1f",
        static_cast<float>(sf::Mouse::getPosition(window).x),
        static_cast<float>(sf::Mouse::getPosition(window).y)
    );

    ImGui::End();
}
