#include<iostream>
using namespace std;

string toUpper(string text){

    for(size_t a=0 ; a<text.size() ; ++a){
        if (text[a]>='a' && text[a]<='z')//Checking the character is lower case
        //To check the character is uppercase, text[a]>='A && text[a]<='Z'  modify text[a]+32
        {
            char temp= static_cast<char>(text[a]-32);
            text[a]=temp;
        }
    }
    return text;
}

class Animal {
        public :

        void eat(){
            cout<<toUpper("I can eat!")<<endl;
        }

        void sleep(){
            cout<<toUpper("I can sleep!")<<endl;

        }
    };


class Dog : public Animal {
        public :
        void bark(){
            cout<<toUpper("I can bark!")<<endl;

        }
    };

int main(){
   
    Dog d ;
    d.eat();
    d.sleep();
    d.bark();
    
}
