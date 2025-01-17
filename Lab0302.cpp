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

vector<string> generateCombinations(const string &digits , const vector<string> &keypad){
    if (digits.empty()) {
        return {""};
    }

    string letters= keypad[digits[0]-'0'];
    vector<string> smallCombinations =generateCombinations(digits.substr(1) , keypad);
    vector<string> result;
    for (string s : smallCombinations){
        for(char l :letters){
            result.push_back(s+l);
        }
    }
    return result;

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

   vector<string> combinations= generateCombinations(keys, keypad);

    cout<<"Output : \n";
    for( string c :combinations){
        cout<<'-'<<c<<endl;
    }

    cout<<"Total combinations : "<<combinations.size();

}