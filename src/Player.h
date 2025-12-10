
#include <SFML/Graphics.hpp>
#include <optional>
#include "Tile.h"

class Player {
public:
    Player();
    void render(sf::RenderWindow& window);
    void setGridPosition(Tile tile);
    std::optional<Tile> tile;
private:
    sf::Texture playerTexture;
    sf::RectangleShape playerShape;
};