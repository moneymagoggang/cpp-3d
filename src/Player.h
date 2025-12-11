
#include <SFML/Graphics.hpp>
#include <optional>
#include "Tile.h"\

class Player {
public:
    Player();
    void render(sf::RenderWindow& window);
    void setGridPosition(Tile tile);
    std::optional<Tile> tile;

    sf::Vector2f PLAYER_SIZE = {50.f, 50.f};
private:
    sf::Texture playerTexture;
    sf::RectangleShape playerShape;
};