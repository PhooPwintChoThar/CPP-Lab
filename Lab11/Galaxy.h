#ifndef GALAXY_H
#define GALAXY_H

#include <vector>
#include "AlienShip.h"

class Galaxy {
public:
    Galaxy();
    void addAlienShip(const AlienShip& ship);
    AlienShip* explore();
    void removeShip(int index);
    std::vector<AlienShip>& getAlienShips() { return alienShips; } // For main() access

private:
    std::vector<AlienShip> alienShips;
};

#endif