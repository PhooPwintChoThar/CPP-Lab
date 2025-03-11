#include "Scanner.h"
#include <cstdlib>

Scanner::Scanner(const std::string& name, int range)
    : name(name), range(range >= 0 && range <= 100 ? range : 40) {}

bool Scanner::scanShip(const AlienShip& target) const {
    return (rand() % 100) < range; // True if scan succeeds
}