#include "AlienShip.h"
#include <cstdlib>

AlienShip::AlienShip(const std::string& name, const std::string& propulsion, int hullStrength, int speed, int evasionChance)
    : Spacecraft(name, propulsion, hullStrength, speed),
      evasionChance(evasionChance >= 0 && evasionChance <= 100 ? evasionChance : 50) {}

bool AlienShip::attemptFlee() const {
    return (rand() % 100) < evasionChance; // True if fleeing succeeds
}