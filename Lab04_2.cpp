#include<iostream>;
#include<iomanip>;
using namespace std;

class PopulationGrowth{
    private:
    double currentPopulation;
    double growthRate;

    public:
    PopulationGrowth(double population, double rate):currentPopulation(population), growthRate(rate)
    {}

    void projectGrowth(int years){

        double population=currentPopulation;
        double annualIncrease;
        int doublingYear=-1;

        cout<<setw(6)<<"Year"<<setw(25)<<"Projected Population"<<setw(25)<<"Annual Increase"<<endl;

        for(int year=1 ; year<=years ; ++year){
            annualIncrease=population*(growthRate/100);
            population+=annualIncrease;
            cout<<setw(6)<<year<<setw(25)<<fixed<<setprecision(0)<<population<<setw(25)<<fixed<<setprecision(0)<<annualIncrease<<endl;

            if (doublingYear==-1 && population>=currentPopulation*2){
                doublingYear=year;
            }
        }

        if (doublingYear!=-1){
            cout<<"The population is expected to double in "<<doublingYear<<" years."<<endl;
        }else{
            cout<<"The population is not expected to double wihin "<<years<<" years."<<endl;
        }
    }
};

int main(){
    double currentPopulation, growthRate;
    cout<<"Enter the current world population : ";
    cin>>currentPopulation;

    cout<<"Enter the annual growth rate (percentage) : ";
    cin>>growthRate;

    PopulationGrowth growth (currentPopulation,growthRate );
    growth.projectGrowth(75);

    return 0;
    }