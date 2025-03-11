#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Book {
    protected:

    string id;
    double fineRate=0.00;

    public:

    Book( string bid , double fine): id(bid) , fineRate(fine){

    }

    virtual double calculateFine( int daysOverdue){
        return daysOverdue*fineRate;
    }

    virtual void displayInfo(){
        cout<<"Book id : "<<id<<endl;

    }
};

class Textbook : public Book {

    private:
    string subject;

    public:

    Textbook( string bid , double fine , string s) : Book(bid, fine), subject(s){}
        

    double calculateFine  (int daysOverdue) override {
        double pay=fineRate+0.5 *daysOverdue ;
        return pay;
    }

    void displayInfo() override{
        cout<<"TextBook id : "<<id<<endl;
        cout<<"Basic Fine rate : "<<fineRate<<endl;
        cout<<"Subject : "<<subject<<endl;

    }
};

class Novel : public Book {

    private:
    string genere;

    public:
    Novel( string bid , double fine , string g) : Book(bid, fine) , genere(g) { }

    double calculateFine  (int daysOverdue) override {
        double pay=fineRate+0.2 *daysOverdue ;
        return pay;
    }

    void displayInfo() override{
        cout<<"Novel id : "<<id<<endl;
        cout<<"Basic Fine rate : "<<fineRate<<endl;
        cout<<"Genere : "<<genere<<endl;

    }


};

double calculateFine (Book* b , int days){
   double f= b->calculateFine(days);
   return f;
}

void displayBook( Book* b){
    b->displayInfo();
}

int main(){
    vector<Book*> bookList={ new Textbook ("T001" , 1 , "Physics") , new Novel("N001" , 0.5 , "Mystery")};
    cout<<"Library Book System"<<endl;
    cout<<"----------------------"<<endl;

    for(auto book :bookList ){
        displayBook(book);
        cout<<"Fine for 5 days overdue : "<<calculateFine(book, 5)<<endl;
        cout<<"------------------------------"<<endl;
    }




}
