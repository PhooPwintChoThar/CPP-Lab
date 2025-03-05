#include<iostream>
#include<string>
#include<vector>
using namespace std;

class CarbonEmitter {
    protected:
    string id;

    public:

    CarbonEmitter( string i): id(i){}

    virtual double getCarbonFootprint () = 0;
    virtual void displayDetails()=0 ;

};


class Factory : public CarbonEmitter {
    double productionHours;
    double energyPerHour ;
    double wastePerHour;

    public: 
    Factory( string i , double p , double e, double w) : CarbonEmitter(i) , productionHours(p) , energyPerHour(e) , wastePerHour(w) {}
    double getCarbonFootprint () override {
        return energyPerHour*productionHours*0.5 + wastePerHour*productionHours*0.2;
    }

    void displayDetails() override{
        cout<<" factory id :"<< id <<endl;
        cout<<" production hours : "<<productionHours<<endl;
        cout<<" energy per hour : "<<energyPerHour<<endl;
        cout<<" waste per hour : "<<wastePerHour<<endl;
    }
};

class Car : public CarbonEmitter {
    protected: 
    double milesDriven , fuelEfficiency ;

    public :
    Car ( string i , double m , double f ) :CarbonEmitter (i) , milesDriven(m) , fuelEfficiency(f) {}
};

class ElectricCar : public Car{
    double batteryCapacity , chargeEfficiency ;

    public: 
    ElectricCar ( string i , double m , double f , double b , double c) :Car(i , m , f) , batteryCapacity(b) , chargeEfficiency(c){}
    double getCarbonFootprint () override {
        return (milesDriven/ fuelEfficiency) * (1/chargeEfficiency)* 0.5;
    }

    void displayDetails() override{
        cout<<" electrical car id :"<< id <<endl;
        cout<<" miles driven : "<<milesDriven<<endl;
        cout<<" fuels efficiency  : "<<fuelEfficiency<<endl;
        cout<<" batter capaity : "<<batteryCapacity<<endl;
        cout<<" charge efficiency  : "<<chargeEfficiency<<endl;
    }
};

class ModifiedCar : public Car {


    public: 

    ModifiedCar ( string i , double m , double f ) : Car( i , m ,f) {}
    double getCarbonFootprint () override {
        return (milesDriven/ fuelEfficiency) * 8.8;
    }

    void displayDetails() override{
        cout<<" modified car id :"<< id <<endl;
        cout<<" miles driven : "<<milesDriven<<endl;

    }

};

class Building : public CarbonEmitter {
    double energyUsage  , numberOfOccupants ;

    public:

    Building ( string i , double e , double n) : CarbonEmitter(i) , energyUsage(e) , numberOfOccupants(n){}
    

    double getCarbonFootprint () override {
        return (energyUsage/ numberOfOccupants) * 0.5 * numberOfOccupants;
    }

    void displayDetails() override{
        cout<<" building id :"<< id <<endl;
        cout<<" energy usage : "<<energyUsage<<endl;
        cout<<" number of Occupants  : "<<numberOfOccupants<<endl;

    }

};


class Bicycle : public CarbonEmitter{
    double milesRidden , manufacturingEmissions ;

    public:
    Bicycle(string i , double m1 , double m2): CarbonEmitter(i) , milesRidden(m1) , manufacturingEmissions(m2) {}

    double getCarbonFootprint () override {
        return manufacturingEmissions/365;
    }

    void displayDetails() override{
        cout<<" bicycle id :"<< id <<endl;
        cout<<" miles ridden : "<<milesRidden<<endl;
        cout<<" manufacturing emissions : "<<manufacturingEmissions<<endl;

    }


};


int main(){

    vector<CarbonEmitter*> emitters;
    string id;

    cout<<" Factory "<<endl;
    cout<<"ID   : ";
    cin>>id;
    cout<<"\nProduction Hours : "<<endl;
    double phrs;
    cin>>phrs;
    while ( phrs < 0 || phrs>24){
        cout<<"\nInvalid!type again : ";
        cin>>phrs;

    }
    

    cout<<"\nENERGY  per Hour : "<<endl;
    double ephrs;
    cin>>ephrs;

    cout<<"\nWaste per Hours : "<<endl;
    double wphrs;
    cin>>wphrs;

    emitters.push_back(new Factory(id, phrs, ephrs,wphrs));

    cout<<"Modified Car "<<endl;
    cout<<" id : ";
    cin>>id;
    cout<<"\nmiles driven : ";
    double mdriven ;
    cin>>mdriven;
    cout<<"\n fuel efficiency : ";
    double feffi;
    cin>>feffi;

    emitters.push_back(new ModifiedCar(id , mdriven, feffi));

    cout<<"\nBicycle"<<endl;
    cout<<" id : ";
    cin>>id;
    cout<<"\n miles ridden : ";
    double mrd;
    cin>>mrd;
    cout<<"\nmanufacturing emissions : ";
    double mem;
    cin>>mem;
    emitters.push_back(new Bicycle(id , mrd, mem));

    double totalFP;
    for (auto e : emitters){
        e->displayDetails();
        totalFP=e->getCarbonFootprint();
    }

    cout<<"Total carbon footprint : "<<totalFP<<endl;

    for ( auto e : emitters){
        delete e;
    }

    
    

}



