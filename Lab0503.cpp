#include <iostream>
#include <vector>
using namespace std;

string toUpper(string name) {
    for (int a = 0; a < name.size(); ++a) {
        if (name[a] >= 'a' && name[a] <= 'z') {
            char temp = static_cast<char>(name[a] - 32);
            name[a] = temp;
        }
    }
    return name;
}

struct Menu {
    string name;
    double price;

    Menu(string n, double p) : name(n), price(p) {} // Constructor for initialization
};

int main() {
    vector<Menu> items = {
        Menu("COFFEE", 35.00),
        Menu("TEA", 25.00),
        Menu("LATTE", 40.00),
        Menu("JUICE", 30.00)
    };

    while (true) {
        cout << "Available Drinks: COFFEE, TEA, LATTE, JUICE\n";
        cout << "Enter drink name to order: ";
        string drink;
        cin >> drink;
        double price = -1;

        // Find the drink price
        for (auto item : items) {
            if (item.name == toUpper(drink))
                price = item.price;
        }

        if (price == -1) {
            cout << "Invalid item!\n";
            continue;
        }

        cout << "Available sizes: SMALL, MEDIUM, LARGE\n";
        cout << "Enter size : ";
        string size;
        cin >> size;

        // Adjust price based on size
        if (toUpper(size) == "SMALL") {
            // No price change
        } else if (toUpper(size) == "MEDIUM") {
            price += 10;
        } else if (toUpper(size) == "LARGE") {
            price += 20;
        } else {
            cout << "Invalid Size!\n";
            continue;
        }

        cout << "Order Details:\n";
        cout << " Drink: " << toUpper(drink)
             << "  Size: " << toUpper(size)
             << "  Price: $" << price << endl;

        cout << "Would you like to order again? (y/n): ";
        char ans;
        cin >> ans;
        if (ans == 'n' || ans == 'N')
            break;
    }

    return 0;
}
