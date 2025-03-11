#include "FleetShip.h"

FleetShip::FleetShip(const std::string& name, const std::string& propulsion, int hullStrength, int speed)
    : Spacecraft(name, propulsion, hullStrength, speed) {}