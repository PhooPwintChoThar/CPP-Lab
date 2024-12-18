#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    vector<string> keypad={"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    cout<<"Enter the digits between 2-9 : ";
    string input;
    cin>>input;

    vector<string> combinations={""};

    for(char digit : input){
        vector<string> temp;
        string letters=keypad[digit - '0'];

        for (string c : combinations){
            for(char l : letters){
                temp.push_back(c + l);
            }
        }

        combinations=temp;
    }

    cout<<"\ninput : "<<input<<endl;
    cout<<"Output : \n";
    for (string c : combinations){
        cout<<"-"<<c<<endl;
    }
    cout<<"Total combinations :"<<combinations.size();
}

