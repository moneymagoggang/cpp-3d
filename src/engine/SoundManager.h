#include <SFML/Audio.hpp>

class SoundManager {
public:
    SoundManager();
    void loadOst();
    void loadWaves();

private:
    sf::Music ost;
    sf::Music waves;



};