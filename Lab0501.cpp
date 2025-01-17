#include<iostream>
using namespace std;

int fibonacci(int n){
    if ( n== 0)
    return 0;
    else if (n==1)
    return 1;
    else
    return fibonacci(n-2) +fibonacci(n-1);
}

int main(){
    int num;
    while(true ){
        cout<<"Enter a non-negative integer : ";
        cin>>num;

        if (num>=0)
        break;

        cout<<"Invalid input!\n";
    }

    for(int x=0 ; x<=num ; ++x){
        cout<<"F ("<<x<<") = " <<fibonacci(x) << (x==num ? " ." : " , ");
    }

    cout<<endl;
    

}