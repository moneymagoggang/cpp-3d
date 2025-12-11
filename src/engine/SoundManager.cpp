#include "SoundManager.h"
#include <iostream>


SoundManager::SoundManager() {
    loadOst();
    loadWaves();
}

void SoundManager::loadOst() {
    if (!ost.openFromFile("../assets/sounds/ost.mp3")) {
        std::cerr << "Failed to load ost.mp3" << std::endl;
    }
    ost.setVolume(15);
    ost.play();
    ost.setLooping(true);
}

void SoundManager::loadWaves() {
    if (!waves.openFromFile("../assets/sounds/waves.mp3")) {
        std::cerr << "Failed to load ost.mp3" << std::endl;
    }
    waves.setVolume(5);
    waves.play();
    waves.setLooping(true);
}

