#include<iostream>
using namespace std;

int main(){

    cout<<"Face length of cube \t Surface area of cube \t Volume of cube"<<endl;
    cout<<"(cm)\t\t\t(cm^2)\t\t\t\t(cm^3)"<<endl;

    for(int length=0 ; length<=4 ; ++length) {
        cout<<length<<"\t\t\t"<<(length*length*6)<<"\t\t\t\t"<<(length*length*length)<<endl;
    }
}