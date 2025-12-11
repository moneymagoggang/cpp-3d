
#include "SFML/Graphics.hpp"
#include "../Tile.h"


class Object {
public:
    Object();
    virtual ~Object() = default;
    virtual void render(sf::RenderWindow &window);
    virtual void setGridPosition(Tile tile);
    std::optional<Tile> tile;

    sf::Vector2f OBJECT_SIZE = {30.f, 30.f};

protected:
    sf::RectangleShape shape;
    sf::Texture texture;

};
