#include<iostream>
#include<cstring>
using namespace std;

void getStringDetails(const char*, int&, int&);
void reverseString(char*);

int main(){
    char string1[80];
    cout << "Enter a string: ";
    cin.getline(string1, 80);

    int vowelCount = 0;
    int length = 0;

    getStringDetails(string1, length, vowelCount);
    cout << "length : " << length << endl << "vowel count: " << vowelCount << endl;

    cout << "Reverse of " << string1 << " is ";
    reverseString(string1);
    cout << string1 << "." << endl;

    char palim[10] = "madam";
    reverseString(palim);
    cout << "Reverse of madam is " << palim << endl;

    return 0;
}

void getStringDetails(const char* s, int& length, int& vowelCount) {
    length = 0;
    vowelCount = 0;

    while (*s != '\0') {
        length++;
        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' ||
            *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U') {
            ++vowelCount;
        }
        ++s;
    }
}

void reverseString(char* s) {
    int l = strlen(s);
    for (int i = 0; i < l / 2; ++i) {
        char temp = s[i];
        s[i] = s[l - 1 - i];
        s[l - 1 - i] = temp;
    }
}
