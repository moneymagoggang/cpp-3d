
#include <imgui.h>
#include <imgui-SFML.h>


class Debug {
public:
    Debug(sf::RenderWindow& window);
    void render(float dt, sf::RenderWindow& window, sf::View& view);

private:
};