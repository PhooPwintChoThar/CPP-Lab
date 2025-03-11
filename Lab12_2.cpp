#include <iostream>
#include <vector>
using namespace std;

class CarbonEmitter {
protected:
    string id;

public:
    CarbonEmitter(string objectId) : id(objectId) {}
    virtual double getCarbonFootprint() = 0;
    virtual void displayDetails() = 0;
    virtual ~CarbonEmitter() {} // Added virtual destructor
};

class Building : public CarbonEmitter {
    double energyUsage;
    int numberOfOccupants;

public:
    Building(string oid, double eu, int no) : CarbonEmitter(oid), energyUsage(eu), numberOfOccupants(no) {}

    double getCarbonFootprint() override {
        return (energyUsage / numberOfOccupants) * 0.5 * numberOfOccupants;
    }

    void displayDetails() override {
        cout << "Building (ID: " << id << ")" << endl;
        cout << "Energy Usage: " << energyUsage << endl;
        cout << "Number Of Occupants: " << numberOfOccupants << endl;
    }
};

class Car : public CarbonEmitter {
protected:
    double milesDriven, fuelEfficiency;

public:
    Car(string objectId, double md, double fe) : CarbonEmitter(objectId), milesDriven(md), fuelEfficiency(fe) {}
};

class ElectricCar : public Car {
    double batteryCapacity, chargeEfficiency;

public:
    ElectricCar(string oid, double md, double fe, double bc, double ce) : Car(oid, md, fe), batteryCapacity(bc), chargeEfficiency(ce) {}

    double getCarbonFootprint() override {
        return (milesDriven / fuelEfficiency) * (1 / chargeEfficiency) * 0.5;
    }

    void displayDetails() override {
        cout << "Electric Car (ID: " << id << ")" << endl;
        cout << "Miles Driven: " << milesDriven << endl;
        cout << "Fuel Efficiency: " << fuelEfficiency << endl;
        cout << "Battery Capacity: " << batteryCapacity << endl;
        cout << "Charge Efficiency: " << chargeEfficiency << endl;
    }
};

class ModifiedCar : public Car {
public:
    ModifiedCar(string oid, double md, double fe) : Car(oid, md, fe) {}

    double getCarbonFootprint() override {
        return (milesDriven / fuelEfficiency) * 8.8;
    }

    void displayDetails() override {
        cout << "Modified Car (ID: " << id << ")" << endl;
        cout << "Miles Driven: " << milesDriven << endl;
        cout << "Fuel Efficiency: " << fuelEfficiency << endl;
    }
};

class Bicycle : public CarbonEmitter {
    double milesRidden, manufacturingEmissions;

public:
    Bicycle(string oid, double mr, double me) : CarbonEmitter(oid), milesRidden(mr), manufacturingEmissions(me) {}

    double getCarbonFootprint() override {
        return manufacturingEmissions / 365;
    }

    void displayDetails() override {
        cout << "Bicycle (ID: " << id << ")" << endl;
        cout << "Miles Ridden: " << milesRidden << endl;
        cout << "Manufacturing Emissions: " << manufacturingEmissions << endl;
    }
};

class Factory : public CarbonEmitter {
    double productionHours, energyPerHour, wastePerHour;

public:
    Factory(string objectId, double phrs, double ephrs, double wphrs) : CarbonEmitter(objectId), productionHours(phrs), energyPerHour(ephrs), wastePerHour(wphrs) {}

    double getCarbonFootprint() override {
        return (energyPerHour * productionHours * 0.5) + (wastePerHour * productionHours * 0.2);
    }

    void displayDetails() override {
        cout << "Factory (ID: " << id << ")" << endl;
        cout << "Production Hours: " << productionHours << endl;
        cout << "Energy Per Hour: " << energyPerHour << endl;
        cout << "Waste Per Hour: " << wastePerHour << endl;
    }
};

void createEmitter(vector<CarbonEmitter*>& emitters) {
    cout << "1. Factory\n2. Electric Car\n3. Modified Car\n4. Building\n5. Bicycle\nYour choice: ";
    int choice;
    cin >> choice;
    string id;
    double val1, val2, val3, val4;

    switch (choice) {
        case 1:
            cout << "Factory Id: "; cin >> id;
            cout << "Production Hours: "; cin >> val1;
            cout << "Energy Per Hour: "; cin >> val2;
            cout << "Waste Per Hour: "; cin >> val3;
            emitters.push_back(new Factory(id, val1, val2, val3));
            break;
        case 2:
            cout << "Electric Car Id: "; cin >> id;
            cout << "Miles Driven: "; cin >> val1;
            cout << "Fuel Efficiency: "; cin >> val2;
            cout << "Battery Capacity: "; cin >> val3;
            cout << "Charge Efficiency: "; cin >> val4;
            emitters.push_back(new ElectricCar(id, val1, val2, val3, val4));
            break;
        case 3:
            cout << "Modified Car Id: "; cin >> id;
            cout << "Miles Driven: "; cin >> val1;
            cout << "Fuel Efficiency: "; cin >> val2;
            emitters.push_back(new ModifiedCar(id, val1, val2));
            break;
        case 4:
            cout << "Building Id: "; cin >> id;
            cout << "Energy Usage: "; cin >> val1;
            cout << "Number of Occupants: "; int occupants; cin >> occupants;
            emitters.push_back(new Building(id, val1, occupants));
            break;
        case 5:
            cout << "Bicycle Id: "; cin >> id;
            cout << "Miles Ridden: "; cin >> val1;
            cout << "Manufacturing Emissions: "; cin >> val2;
            emitters.push_back(new Bicycle(id, val1, val2));
            break;
        default:
            cout << "Invalid Choice!" << endl;
            break;
    }
}

int main() {
    vector<CarbonEmitter*> emitters;
    cout << "Carbon Footprint Calculation System\n-------------------------------------" << endl;
    while (true) {
        cout << "1. Create Carbon Emitter Object\n2. Show all objects\n3. Exit\nYour choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                createEmitter(emitters);
                break;
            case 2:
                for (CarbonEmitter* e : emitters) {
                    e->displayDetails();
                    cout << "Emitted carbon footprint: " << e->getCarbonFootprint() << " kg." << endl;
                    cout << "-----------------------------------------------------------" << endl;
                }
                break;
            case 3:
                for (CarbonEmitter* e : emitters) delete e;
                return 0;
            default:
                cout << "Invalid Choice!" << endl;
                break;
        }
    }
    return 0;
}
