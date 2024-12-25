#include<iostream>
#include<string>
using namespace std;

class HeartRateMonitor{
    private:
    string FirstName;
    string LastName;
    int BirthYear;
    int BirthMonth;
    int BirthDay;
    int age;
    int MaxHeartRate;
    int targetHeartRateMax;
    int targetHeartRateMin;


    void calculateHeartRate(){
        int currentYear=2023;
        int currentMonth=12;
        int currentDay=28;
        age=currentYear-BirthYear;
        if(BirthMonth>currentMonth|| (BirthMonth==currentMonth && BirthDay > currentDay))
        --age;

        MaxHeartRate=220-age;
        targetHeartRateMin=static_cast<int>(MaxHeartRate*0.5);
        targetHeartRateMax=static_cast<int>(MaxHeartRate*0.85);



    }

    public:
    HeartRateMonitor(const string& firstName, const string& lastName, int birthYear, int birthMonth, int birthDay) 
    : FirstName( firstName), LastName(lastName), BirthYear(birthYear) , BirthMonth(birthMonth) , BirthDay(birthDay){
        calculateHeartRate();
    }

    void displayInformaion () const{

        cout<<"Hello, "<<age<<"years old"<<FirstName<<" "<<LastName<<"."<<endl;
        cout<<"Your maximum heart rate should be "<<MaxHeartRate<<" beats per minute";
        cout<<"Your target heart range is "<<targetHeartRateMin<<"-"<<targetHeartRateMax<<" beats per minute.";

    }


};


int main(){
    string firstName, lastName;
    int birthYear, birthMonth, birthDay;

    cout<<"Enter your first name :";
    cin>>firstName;
    cout<<"\nEnter your last name : ";
    cin>>lastName;
    cout<<"\nEnter your birth year (YYYY) : ";
    cin>>birthYear;
    cout<<"\nEnter your birth month (MM) : ";
    cin>>birthMonth;
    cout<<"\nEnter your birth day(DD) : ";
    cin>>birthDay;

    HeartRateMonitor person1(firstName, lastName, birthYear, birthMonth, birthDay);
    person1.displayInformaion();

    return 0;

}