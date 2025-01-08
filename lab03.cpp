#include<iostream>
using namespace std;


enum Size{
    SMALL,
    MEDIUM, 
    LARGE
};

enum DrinkType{
    COFFEE,
    TEA,
    LATTE,
    JUICE
};


int main(){
    while (true){
        cout<<"Welcome to Coffee Shop!"<<endl;
    cout<<"Select your drink:\n";
    cout<<"1.COFFEE 2.TEA 3.LATTE 4.JUICE"<<endl;
    cout<<"Enter number (1-4):";
    int choice;
    cin>>choice;
    double base_price;
    string drink;

    switch(choice){
        case 1:
        drink="COFFEE";
        base_price=35.00;
        break;
        case 2:
        drink="TEA";
        base_price=25.00;
        break;
        case 3:
        drink="LATTE";
        base_price=40.00;
        break;
        case 4:
        drink="JUICE";
        base_price=30.00;
        break;
        default :
        cout<<"\n Invalid choice"<<endl;
        continue;

    }

    cout<<"Select size:"<<endl;
    cout<<"1.SMALL 2.MEDIUM 3.LARGE \n";
    cout<<"Enter number (1-3) : ";
    int size;
    cin>>size;
    double price;
    string d_size;

    switch(size){
        case 1:
        d_size="SMALL";
        price=base_price;
        break;
        case 2:
        d_size="MEDIUM";
        price=base_price+10.00;
        break;
        case 3:
        d_size="LARGE";
        price=base_price+20.00;
        break;
        default :
        cout<<"\n Invalid size"<<endl;
        continue;

    }

    cout<<"Order Details : \n";
    cout<<"Drink : "<<drink<<"  Size : "<<d_size<<"  Price : $"<<price;
    cout<<"\n Would you like to order again (y/n) : ";
    char q;
    cin>>q;
    if (q=='y' || q=='Y')
    continue;
    else
    {
        cout<<"\nThank you.";
        break;
    }
    

    }

}