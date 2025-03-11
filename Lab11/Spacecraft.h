#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <string>

class Spacecraft {
public:
    Spacecraft(const std::string& name, const std::string& propulsion, int hullStrength, int speed);
    std::string getName() const { return name; }
    std::string getPropulsion() const { return propulsion; }
    int getHullStrength() const { return hullStrength; }
    int getSpeed() const { return speed; }

protected:
    std::string name;
    std::string propulsion;
    int hullStrength;
    int speed;
};

#endif