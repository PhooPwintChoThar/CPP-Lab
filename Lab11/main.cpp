#include <iostream>
#include <vector>
#include <ctime>
#include "Spacecraft.h"
#include "AlienShip.h"
#include "FleetShip.h"
#include "Scanner.h"
#include "TractorBeam.h"
#include "Player.h"
#include "Galaxy.h"

// Helper function to display player's inventory
void displayInventory(const Player& player) {
    std::cout << "Scanners:\n";
    if (player.getScanners().empty()) {
        std::cout << "  None\n";
    } else {
        for (size_t i = 0; i < player.getScanners().size(); ++i) {
            std::cout << "  " << i + 1 << ". " << player.getScanners()[i].getName()
                      << " (Range: " << player.getScanners()[i].getRange() << ")\n";
        }
    }
    std::cout << "Fleet:\n";
    if (player.getFleet().empty()) {
        std::cout << "  None\n";
    } else {
        for (const auto& ship : player.getFleet()) {
            std::cout << "  - " << ship.getName() << " (Hull: " << ship.getHullStrength() << ")\n";
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator
    Player player;
    Galaxy galaxy;

    // Initialize player with scanners
    player.addScanner(Scanner("Basic Scanner", 40));
    player.addScanner(Scanner("Enhanced Scanner", 60));
    player.addScanner(Scanner("LongRange Scanner", 80));

    // Initialize galaxy with alien ships
    galaxy.addAlienShip(AlienShip("Scout", "Ion Drive", 30, 80, 70));
    galaxy.addAlienShip(AlienShip("Fighter", "Plasma Thruster", 60, 50, 40));
    galaxy.addAlienShip(AlienShip("Frigate", "Warp Engine", 80, 30, 20));
    galaxy.addAlienShip(AlienShip("Drone", "Solar Sail", 20, 60, 60));
    galaxy.addAlienShip(AlienShip("Destroyer", "Fusion Core", 90, 40, 30));

    std::cout << "Welcome to Space Explorer!\nGoal: Capture all 5 ships before running out of scanners.\n";

    while (true) {
        std::cout << "\nOptions:\n  1. Explore\n  2. Quit\n  3. Check Inventory\nEnter choice: ";
        int choice;
        std::cin >> choice;

        if (choice == 2) {
            std::cout << "Quitting game.\n";
            break;
        } else if (choice == 3) {
            displayInventory(player);
            continue;
        } else if (choice != 1) {
            std::cout << "Invalid choice. Try again.\n";
            continue;
        }

        AlienShip* target = galaxy.explore();
        if (!target) {
            std::cout << "No ships encountered in this sector.\n";
            continue;
        }

        int shipIndex = -1;
        for (size_t i = 0; i < galaxy.getAlienShips().size(); ++i) {
            if (&galaxy.getAlienShips()[i] == target) {
                shipIndex = i;
                break;
            }
        }

        while (target) { // Keep encounter active until ship is handled
            std::cout << "\nEncountered a " << target->getName() << "!\n";
            std::cout << "Options:\n  1. Scan and Attempt Capture\n";
            if (!player.getTractorBeam()) { // Only show if no Tractor Beam is equipped
                std::cout << "  2. Equip Tractor Beam (if not equipped)\n";
            }
            std::cout << "Enter choice: ";
            std::cin >> choice;

            if (choice == 1) {
                if (player.getScanners().empty()) {
                    std::cout << "No scanners remaining! Game Over.\n";
                    break;
                }

                std::cout << "Choose a scanner (1-" << player.getScanners().size() << "):\n";
                displayInventory(player);
                int scannerIndex;
                std::cout << "Enter choice: ";
                std::cin >> scannerIndex;
                scannerIndex--; // Adjust for 0-based indexing

                if (scannerIndex < 0 || scannerIndex >= static_cast<int>(player.getScanners().size())) {
                    std::cout << "Invalid scanner choice.\n";
                    continue; // Stay in encounter loop
                }

                std::cout << "Scanning with " << player.getScanners()[scannerIndex].getName() << "...\n";
                if (player.captureShip(*target, scannerIndex)) {
                    std::cout << "Captured the " << target->getName() << " successfully!\n";
                    galaxy.removeShip(shipIndex);
                    target = nullptr; // End encounter
                } else {
                    std::cout << "Failed to capture the " << target->getName() << ".\n";
                    if (target->attemptFlee()) {
                        std::cout << "The " << target->getName() << " fled the sector!\n";
                        galaxy.removeShip(shipIndex);
                        target = nullptr; // End encounter
                    } else {
                        std::cout << "The " << target->getName() << " remains in range.\n";
                    }
                }

                if (galaxy.getAlienShips().empty()) {
                    std::cout << "All ships captured! Congratulations, you win!\n";
                    break;
                }
                if (player.getScanners().empty()) {
                    std::cout << "No scanners left with ships remaining! Game Over.\n";
                    break;
                }
            } else if (choice == 2 && !player.getTractorBeam()) {
                std::cout << "Choose Tractor Beam:\n  1. Standard Beam (Strength: 20)\n  2. Heavy Beam (Strength: 40)\nEnter choice: ";
                int beamChoice;
                std::cin >> beamChoice;
                if (beamChoice == 1) {
                    player.equipTractorBeam(new TractorBeam("Standard Beam", 20));
                } else if (beamChoice == 2) {
                    player.equipTractorBeam(new TractorBeam("Heavy Beam", 40));
                } else {
                    std::cout << "Invalid choice. No beam equipped.\n";
                    continue; // Stay in encounter loop
                }
                std::cout << "Equipped " << player.getTractorBeam()->getName() << "!\n";
            } else {
                std::cout << "Invalid choice. Try again.\n";
                continue; // Stay in encounter loop
            }
        }

        if (galaxy.getAlienShips().empty()) {
            std::cout << "All ships captured! Congratulations, you win!\n";
            break;
        }
        if (player.getScanners().empty()) {
            std::cout << "No scanners left with ships remaining! Game Over.\n";
            break;
        }
    }

    std::cout << "\nFinal Inventory:\n";
    displayInventory(player);
    return 0;
}
