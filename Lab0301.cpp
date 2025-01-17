#include<iostream>
#include<string>
#include<vector>
#include<sstream>//Just for practice
using namespace std;

//You don't need to use this function in this lab
bool StringIsDigits(const string &input){
    istringstream iss (input);
    int num;
    iss>>num;
    return iss.eof() && !iss.fail();
}

int main(){
    string keys;
    vector<string> keypad={"" , "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    cout<<"Input : ";
    cin>>keys;

    if (!StringIsDigits(keys)){
        cout<<"Invalid Keys!Exiting from the program..";
        return 1;
    } 

    vector<string> combinations = {""};
    for(char k :keys){
        string letters=keypad[k-'0'];
        vector<string> temp;
        for (string s :combinations ){
            for(char l : letters ){
                temp.push_back(s+l);
            }
        }
        combinations=temp;

    }

    cout<<"Output : \n";
    for( string c :combinations){
        cout<<'-'<<c<<endl;
    }

    cout<<"Total combinations : "<<combinations.size();

}