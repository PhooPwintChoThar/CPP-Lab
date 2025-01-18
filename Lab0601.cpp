#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    //create test.txt first
    ifstream file("test.txt");
    
    if (!file){
        cerr<<"Error : Unable to open the file!"<<endl;
        return 1;
    }

    cout<<"File opened successfully!"<<endl;
    string line;
    while( getline(file , line)){
        cout<<"Line size : "<<line.size()<<" ---"<<line<<endl;
    }

    file.close();
    cout<<"File reading completed.\n";
    return 0;
}