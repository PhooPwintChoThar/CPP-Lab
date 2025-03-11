#include "Player.h"
#include <cstdlib>

Player::Player() : tractorBeam(nullptr) {}

Player::~Player() {
    delete tractorBeam; // Clean up dynamically allocated tractorBeam
}

void Player::addScanner(const Scanner& scanner) {
    scanners.push_back(scanner);
}

void Player::equipTractorBeam(TractorBeam* beam) {
    delete tractorBeam; // Delete old beam if it exists
    tractorBeam = beam;
}

bool Player::captureShip(const AlienShip& target, int scannerIndex) {
    if (scannerIndex < 0 || scannerIndex >= static_cast<int>(scanners.size())) {
        return false; // Invalid index
    }
    if (!scanners[scannerIndex].scanShip(target)) {
        scanners.erase(scanners.begin() + scannerIndex); // Remove scanner on failure
        return false;
    }
    int totalChance = 50; // Base chance
    if (tractorBeam) {
        totalChance += tractorBeam->captureShip(target); // Add bonus if equipped
    }
    bool success = (rand() % 100) < totalChance;
    if (success) {
        fleet.push_back(FleetShip(target.getName(), target.getPropulsion(),
                                  target.getHullStrength(), target.getSpeed()));
    }
    scanners.erase(scanners.begin() + scannerIndex); // Remove scanner after use
    return success;
}