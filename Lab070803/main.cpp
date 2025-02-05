#include "Album.h"
#include <vector>
#include <iostream>
using namespace std;

void listAlbums(const std::vector<Album>& albums) {
    std::cout << "\nAvailable Albums:\n";
    for (size_t i = 0; i < albums.size(); ++i) {
        std::cout << i + 1 << ". " << albums[i].getTitle()
                  << " by " << albums[i].getArtist()
                  << " - $" << albums[i].getPrice()
                  << " (" << albums[i].getCopies() << " copies available)\n";
    }
}

void purchaseAlbum(std::vector<Album>& albums, int choice) {
    if (choice > 0 && choice <= albums.size()) {
        albums[choice - 1].purchaseAlbum();
    } else {
        std::cout << "Invalid selection!\n";
    }
}

int main() {
    std::vector<Album> albums = {
        Album("Thriller", "Michael Jackson", 15.99, 5),
        Album("Back in Black", "AC/DC", 12.99, 3),
        Album("The Dark Side of the Moon", "Pink Floyd", 14.99, 4)
    };

    int choice;
    do {
        std::cout << "\n==== Online Music Store ====\n";
        std::cout << "1. List All Albums\n";
        std::cout << "2. Purchase an Album\n";
        std::cout << "3. View Sales Statistics\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                listAlbums(albums);
                break;
            case 2: {
                int albumChoice;
                listAlbums(albums);
                std::cout << "Select an album to purchase: ";
                std::cin >> albumChoice;
                purchaseAlbum(albums, albumChoice);
                break;
            }
            case 3:
                std::cout << "Total Albums in Inventory: " << Album::getTotalAlbums() << "\n";
                std::cout << "Total Revenue: $" << Album::getTotalSales<< "\n";
                break;
            case 4:
                std::cout << "Thank you for visiting!\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
