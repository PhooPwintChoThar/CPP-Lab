#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class PopulationGrowth {

    private:
    double initialPopulation;
    double growthRate;

    public:
    PopulationGrowth(double population, double rate) : initialPopulation(population) , growthRate(rate) {

    }

    void calculatePopulationGrownth( int years){
        double currentPopulation=initialPopulation;
        double increasedPopulation;
        const double rate=growthRate;

        int doubledYear=-3;//the year which will double the population we  need to set initial  negative value  to avoid conflicts
        cout<<setw(7)<<left<<"Year"<<setw(20)<<"Projected Population"<<setw(20)<<"Annual Increase"<<endl;

        for(int year=1 ; year<=years ; ++year){
            double increased= currentPopulation *(rate/100);
            increasedPopulation=currentPopulation+increased;
            cout<<fixed;
            cout<<setw(7)<<left<<year<<setw(20)<<setprecision(0)<<currentPopulation<<setw(20)<<setprecision(0)<<increasedPopulation<<endl;
            currentPopulation=increasedPopulation;

            if (doubledYear==-3 && currentPopulation>=initialPopulation*2){
                doubledYear=year;
            }
        }

        cout<<"The population "<<(doubledYear == -3 ? "will not" : " will ") <<" be doubled in "<<( doubledYear != -3 ? doubledYear: years )<< " years. \n";
    }
};

int main(){
    cout<<"Enter the current world population : ";
    double popu;
    cin>>popu;

    cout<<"Enter the annual growth rate (percentage ) : ";
    double percen;
    cin>>percen;

    PopulationGrowth p(popu, percen);
    p.calculatePopulationGrownth(75);
}