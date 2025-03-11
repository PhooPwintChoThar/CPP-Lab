#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Book {
    protected:
    string id ;
    double fineRate;


    public:

    Book ( string bookId , double fine):id(bookId), fineRate(fine){}

    virtual double calculateFine( int daysOverdue){
        return fineRate;
    }

    virtual void displayInfo (){
        cout<<"Book (ID :"<<id<<")"<<endl;
        cout<<"Fine Rate : $"<<fineRate<<endl;
    }

};


class Textbook : public Book {
    string subject;

    public:
    Textbook ( string bookId , double fine , string sub): subject(sub) , Book(bookId, fine){}

    double calculateFine(int daysOverdue) override {
        return fineRate + (0.5 * daysOverdue); 
    }

    void displayInfo () override {
        cout<<"Textbook (ID: "<<id<<")"<<endl;
        cout<<"Fine Rate : $"<<fineRate<<endl;
        cout<<"Subject : "<<subject<<endl;
    }

};

class Novel : public Book {
    string genre;

    public:
    Novel ( string bookId , double fine , string gen): genre(gen) , Book(bookId, fine){}

    double calculateFine (int daysOverdue) override {

        return fineRate + (0.2 * daysOverdue); 

    }

    void displayInfo () override {
        cout<<"Novel Book  (ID: "<<id<<")"<<endl;
        cout<<"Fine Rate : $"<<fineRate<<endl;
        cout<<"Genre : "<<genre<<endl;
    }


};


int main(){
    vector<Book *> books = {new Textbook("T001", 1 , "Physics") , new Novel ("N001" , 0.5 , "Mystery")};
    cout<<"Library Book System"<<endl;
    cout<<"--------------------------------------"<<endl;
    for(auto book : books){
    book->displayInfo();
    cout<<"Fine for 5 days overdue : $"<<book->calculateFine(5)<<endl;
    cout<<"--------------------------------------"<<endl;
    }
}

