#include<iostream>
#include<cstring>
using namespace std;

void concatenateStrings (char * , const char *, int);
bool isSubstring (char * , char *);

int main(){
    char string1[80];
    char string2[80];

    cout<<"Enter two strings : ";
    cin>>string1>>string2;
    concatenateStrings(string1 , string2, 80);
    cout<<"Concatenated string : "<<string1<<endl;

    char shortstring[10]="hi";
    char longstring[10]="123456789";
    concatenateStrings(shortstring , longstring, 10);
    

    cout<<"Enter two strings which will be substrings : ";
    cin>>string1>>string2;
    cout<<string1<<(isSubstring(string2 , string1)?" is ":" is not ")<<" a substring of "<<string2<<endl;

    


}


void concatenateStrings (char *s1 , const char *s2 , int buffersize){
    int length1=strlen(s1);
    int length2=strlen(s2);

    if(length1+length2>=buffersize){
        cout<<"Error: not enough space to concatenate strings"<<endl;
        return ;
      
    }

    s1+=length1;
    while((*s1++=*s2++));

}

bool isSubstring(char* s1 , char* s2){
     int length1=strlen(s1);
    int length2=strlen(s2);

    if (length2> length1) return false;
    for(int i=0 ; i<=length1-length2 ; ++i ){
        if(strncmp(&s1[0], s2, length2)==0)
        return true;
    }

    return false;

}