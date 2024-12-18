#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> keypad={"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void generateCombnations (string digits, string current, int index, vector<string>& result){
    if (index==digits.size()){
        result.push_back(current);
        return;

    }

    string letters=keypad[digits[index]-'0'];
    for(char letter:letters){
        generateCombnations(digits, current+letter, index+1, result);
    }
}


int main(){
    string input ;
    cout<<"Enter the digits 2-9 : ";
    cin>>input;

    vector<string> result;
    generateCombnations(input,"",0, result);

    cout<<"\ninput : "<<input<<endl;
    cout<<"Output : \n";
    for (string c : result){
        cout<<"-"<<c<<endl;
    }
    cout<<"Total combinations :"<<result.size();



}