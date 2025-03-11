#ifndef FLEETSHIP_H
#define FLEETSHIP_H

#include "Spacecraft.h"

class FleetShip : public Spacecraft {
public:
    FleetShip(const std::string& name, const std::string& propulsion, int hullStrength, int speed);
};

#endif