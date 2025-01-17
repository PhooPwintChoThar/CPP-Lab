#include<iostream>
#include<string>
using namespace std;

class HeartRateMonitor {
    private :
    int age;
    string first_name;
    string last_name;
    int maxHeartRate;
    int minRange;
    int maxRange;

    int calculateAge(const int &byear , const int &bmonth , const int &bday){
        int tempage=2023-byear;
        if (bmonth > 12 || (bmonth==12 && bday>28))
        --tempage;

        return tempage;

    }

    public :
    HeartRateMonitor(string firstname,string lastname,int byear , int bmonth ,int bday ) : first_name(firstname) , last_name(lastname){
        age=calculateAge(byear, bmonth, bday);
        maxHeartRate=220-age;
        minRange=maxHeartRate*50/100;
        maxRange=maxHeartRate*85/100;
    }
    void displayInformation(){
            cout<<"Hello, "<<age<<" years old "<<first_name<<" "<<last_name<<"."<<endl;
            cout<<"Your maximum heart rate should be "<<maxHeartRate<<" beats per minute."<<endl;
            cout<<"Your target heart rate range is "<<minRange<<"-"<<maxRange<<" beats per minute."<<endl;
    }
};


int main(){

    cout<<"Enter your first name : ";
    string f;
    getline(cin, f);

    cout<<"Enter your last name : ";
    string l;
    getline(cin, l);

    cout<<"Enter your birth year (YYYY) : ";
    int year;
    cin>>year;

    cout<<"Enter your birth month (MM) : ";
    int month;
    cin>>month;

    cout<<"Enter your birth day (DD) : ";
    int day;
    cin>>day;

    HeartRateMonitor h1(f,l, year, month, day);
    h1.displayInformation();
    
}