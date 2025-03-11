#include "Galaxy.h"
#include <cstdlib>

Galaxy::Galaxy() {}

void Galaxy::addAlienShip(const AlienShip& ship) {
    alienShips.push_back(ship);
}

AlienShip* Galaxy::explore() {
    if (alienShips.empty() || (rand() % 100) >= 25) {
        return nullptr; // 25% chance of encounter
    }
    int index = rand() % alienShips.size();
    return &alienShips[index];
}

void Galaxy::removeShip(int index) {
    if (index >= 0 && index < static_cast<int>(alienShips.size())) {
        alienShips.erase(alienShips.begin() + index);
    }
}