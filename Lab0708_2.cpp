#include<iostream>
#include<cstring>
using namespace std;
void reverseString(char *);
void getStringDetails ( const char* , int &, int&);

int main(){
    char string1[80];
    cout<<"Enter a string : ";
    cin.getline(string1, 80);
    
    int vowelCount=0;
    int length =0;

    getStringDetails(string1 , length , vowelCount);

    cout<<"Length : "<<length<<" | Vowel count : "<<vowelCount<<endl;
    reverseString(string1);
    cout<<"Reversed : "<<string1<<endl;

    return 0;
}

void getStringDetails (const char* s ,int &length , int &vowelCount){
    length = 0;
    vowelCount = 0;
    while(*s != '\0'){
        ++length;
        if (*s=='a' || *s=='e' || *s=='i' || *s=='o' || *s=='u')
        ++vowelCount;
        ++s;
    }

}

void reverseString( char * s){
    int len= strlen(s);
    for(int i=0 ; i < len/2 ; ++i ){
        char temp=s[len-1-i];
        s[len-1-i]=s[i];
        s[i]=temp;

    }
}