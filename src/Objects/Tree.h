

#include "Object.h"

class Tree : public Object {
public:
    Tree();
    void render(sf::RenderWindow &window) override;
};
