
#include <SFML/Graphics.hpp>
class Player {
public:
    Player();
    void render(float dt, sf::RenderWindow& window);

private:
    sf::Texture playerTexture;
    sf::RectangleShape playerShape;
};