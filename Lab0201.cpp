#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
    string player1,player2;
    cout<<" Enter Player 1 's name : ";
    getline(cin , player1);

    cout<<" Enter Player 2 's name : ";
    getline(cin , player2);

    string p1=" Player 1 : "+player1+" ";
    string p2=" Player 2 : "+player2+" ";
    string display1='*'+p1+'*'+p2+'*';
    string longer_bound(display1.size(),'*');
    string m1(p1.size(), ' ');
    string m2(p2.size(), ' ');
    string middle_bound='*'+m1+'*'+m2+'*';

    //First output
    cout<<longer_bound<<endl;
    cout<<middle_bound<<endl;
    cout<<display1<<endl;
    cout<<middle_bound<<endl;
    cout<<longer_bound<<endl;

    
    int longer_bound2_size= p1.size()>p2.size() ? (p1.size()+2): (p2.size()+2) ;
    string longer_bound2( longer_bound2_size , '*');
    int msize=longer_bound2_size-2;
    string m3(msize, ' ');
    string middle_bound2='*'+m3+'*';
    
    //Second output
    cout<<longer_bound2<<endl;
    cout<<middle_bound2<<endl;
    cout<<'*'<<left<<setw(longer_bound2_size-2)<<p1<<'*'<<endl;
    cout<<middle_bound2<<endl;
    cout<<longer_bound2<<endl;
    cout<<middle_bound2<<endl;
    cout<<'*'<<setw(longer_bound2_size-2)<<p2<<'*'<<endl;
    cout<<middle_bound2<<endl;
    cout<<longer_bound2<<endl;
}
