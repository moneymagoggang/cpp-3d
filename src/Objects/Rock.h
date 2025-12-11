

#include "Object.h"

class Rock : public Object {
public:
    Rock();
    void render(sf::RenderWindow &window) override;
};
