#include "Spacecraft.h"

Spacecraft::Spacecraft(const std::string& name, const std::string& propulsion, int hullStrength, int speed)
    : name(name), propulsion(propulsion),
      hullStrength(hullStrength >= 0 && hullStrength <= 100 ? hullStrength : 50),
      speed(speed >= 0 && speed <= 100 ? speed : 50) {}