#ifndef ALIENSHIP_H
#define ALIENSHIP_H

#include "Spacecraft.h"

class AlienShip : public Spacecraft {
public:
    AlienShip(const std::string& name, const std::string& propulsion, int hullStrength, int speed, int evasionChance);
    int getEvasionChance() const { return evasionChance; }
    bool attemptFlee() const;

private:
    int evasionChance;
};

#endif