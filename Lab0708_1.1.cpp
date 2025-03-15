#include <iostream>
#include <cstring>
using namespace std;

void concatenateStrings(char *, const char *, int);
bool isSubstring (const char* , const char*);

int main() {
    char string1[80];
    char string2[80];

    cout << "Enter two strings: ";
    cin.getline(string1 , 80);
    cin.getline(string2 , 80);

    concatenateStrings(string1, string2, 80);
    cout << "Concatenated string: " << string1 << endl;

    cout<<"\nEnter main string :";
    cin.getline(string1 , 80);

    cout<<"Enter a substring : ";
    cin.getline(string2 , 80);

    cout<<string2<<( isSubstring(string1 , string2) ? " is " : " is not ")<<" a substring of "<<string1<<" ."<<endl;


    return 0;
}

void concatenateStrings(char *s1, const char *s2, int maxSize) {
    int length1 = strlen(s1);
    int length2 = strlen(s2);

    // Check if there's enough space for s2 + null terminator
    if (length1 + length2 >= maxSize) {
        cout << "Error: Not enough space to concatenate the strings!" << endl;
        return;
    }

    // Move s1 pointer to the end
    while (*s1 != '\0') ++s1;

    // Append s2 to s1
    for (; (*s1 = *s2); ++s1, ++s2);
}

bool isSubstring( const char* s1 , const char* s2){
    int length1 = strlen(s1);
    int length2 = strlen(s2);

    if (length2>length1)
    return false;

    
    for(int i=0 ; i <= length1-length2 ; ++i){
        int j;
        for(j=0 ; j<length2 ; j++){
            if (s1[i+j]!=s2[j])
            break;
        }

        if (j==length2)
            return true;
    }

    return false;

}