#include<iostream>
#include<cstring>
using namespace std;

void concatenateStrings ( char * , const char *);

int main(){
    char string1[80];
    char string2[80];

    cout<<"Enter two strings : ";
    cin>> string1 >> string2 ;//cin stops reading at whitespace, meaning it won't capture multi-word inputs.

    concatenateStrings(string1 , string2);
    cout<<"Concatenated string : "<<string1<<endl;
    return 0;

}

void concatenateStrings (char * s1 , const char *s2 )
//s1 is a pointer to the first string (modifiable).
//s2 is a pointer to the second string (read-only due to const).
{
    while(*s1 != '\0') ++ s1;//The loop moves s1 forward until it reaches the null terminator (\0), which marks the end of the first string.
    for( ; (*s1 = *s2) ; ++s1 , ++s2);
    //*s1 = *s2 assigns the current character of s2 to s1.
    //++s1 and ++s2 move both pointers to the next character.
    //The loop stops when *s2 == '\0', ensuring that s1 is properly null-terminated.
}

