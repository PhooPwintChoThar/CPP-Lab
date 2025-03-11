#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include "AlienShip.h"

class Scanner {
public:
    Scanner(const std::string& name, int range);
    bool scanShip(const AlienShip& target) const;
    std::string getName() const { return name; }
    int getRange() const { return range; }

private:
    std::string name;
    int range;
};

#endif