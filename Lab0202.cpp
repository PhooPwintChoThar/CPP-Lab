#include<iostream>
using namespace std;

int main(){
    int size;
    while(true){
    cout<<"Enter the size : ";
    cin>> size;
    if (size>=0){
        break;
    }
    cout<<"Invalid size!\n";
    }
    
    //output1
    for(int line=0 ; line<size ; ++line){
        for( int star=0 ; star<=line ; ++star){
            cout<<'*';
        }
        cout<<endl;      
    }

    cout<<endl<<endl<<endl;

    //output2 
    int t_size=size*2-1;
    for(int line=0 ; line<t_size; ++line){

        if (line<=t_size/2){

            for( int star=0 ; star<=line ; ++star){
            cout<<'*';
        }
        cout<<endl;  

        }else{
        
        int subtract=(line-size)*2+2;
        for( int star=0 ; star<=line-subtract; ++star){
            cout<<'*';
        }

        cout<<endl;
        
        }

        

    }
}