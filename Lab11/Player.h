#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Scanner.h"
#include "FleetShip.h"
#include "TractorBeam.h"

class Player {
public:
    Player();
    ~Player(); // Destructor to delete tractorBeam
    void addScanner(const Scanner& scanner);
    void equipTractorBeam(TractorBeam* beam);
    bool captureShip(const AlienShip& target, int scannerIndex);
    std::vector<Scanner> getScanners() const { return scanners; }
    std::vector<FleetShip> getFleet() const { return fleet; }
    TractorBeam* getTractorBeam() const { return tractorBeam; } // New getter

private:
    std::vector<Scanner> scanners;
    std::vector<FleetShip> fleet;
    TractorBeam* tractorBeam;
};

#endif