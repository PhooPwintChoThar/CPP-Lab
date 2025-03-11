#ifndef TRACTORBEAM_H
#define TRACTORBEAM_H

#include <string>
#include "AlienShip.h"

class TractorBeam {
public:
    TractorBeam(const std::string& name, int strength);
    int captureShip(const AlienShip& target) const;
    std::string getName() const { return name; }
    int getStrength() const { return strength; }

private:
    std::string name;
    int strength;
};

#endif