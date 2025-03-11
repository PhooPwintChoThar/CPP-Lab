#include "TractorBeam.h"

TractorBeam::TractorBeam(const std::string& name, int strength)
    : name(name), strength(strength >= 0 && strength <= 100 ? strength : 20) {}

int TractorBeam::captureShip(const AlienShip& target) const {
    int bonus = strength - (target.getHullStrength() / 5);
    return bonus < 0 ? 0 : bonus; // Minimum bonus is 0
}