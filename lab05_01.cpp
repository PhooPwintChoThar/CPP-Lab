#include<iostream>
using namespace std;

int fibonacci(int n);

int main(){

    int number;
    while (true){
        cout<<"Enter a non-negative integer to cpute the fibonacci sequence : ";
       
        cin>>number;
        if (number>=0)
        break;

    }

    for (int i=0 ; i<=number; ++i){
    cout<<"F("<<i<<") = "<<fibonacci(i)<<endl;}
}

int fibonacci(int n){
    if (n==0)
    return 0;
    else if (n==1){
    return 1;
    }else
    return fibonacci(n-1)+fibonacci(n-2);
}
