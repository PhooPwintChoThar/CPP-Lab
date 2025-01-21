#include<iostream>
using namespace std;
#include<random>
#include<sstream>
#include<limits>

string generateQuestion (int level){


        random_device rd;
        mt19937 gen(rd());
        string num1;
        string num2;
        string operators;
        uniform_int_distribution<int> oneDigit(0,9);
        uniform_int_distribution<int> twoDigit(10,99);
        uniform_int_distribution<int> threeDigit(100,999);

        switch (level){
           case 1:
                
                num1=to_string(oneDigit(gen));
                num2=to_string(oneDigit(gen));
                break;
            case 2:
               
                num1=to_string(twoDigit(gen));
                num2=to_string(twoDigit(gen));
                break;
            case 3:
               
                num1=to_string(threeDigit(gen));
                num2=to_string(threeDigit(gen));
                break;

        }

        uniform_int_distribution<int> oper(0,2);
        int op=oper(gen);

        switch (op){
            case 0:
            operators="+";
            break;

            case 1:
            operators="-";
            break;

            case 2:
            operators ="*";
            break;
        }

        string question=num1+" "+operators+" "+ num2;
        return question;

    }

    int calculateAnswer(string question){

        istringstream iss(question);
        int num1;
        char op;
        int num2;
        iss>>num1;
        iss>>op;
        iss>>num2;

        if (op=='+'){
            return num1+num2;
        } else if (op=='-'){
            return num1-num2;
        } else if (op=='*'){
            return num1*num2;
        }

        return 0;
    }

    int main(){

        while(true){
            
        cout<<"Difficulty Level (1-3) : ";
        int level;
        while(!(cin>>level) || level<1 || level>3){
            cout<<"Invaild Input! Enter level again : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max() , '\n');
        }
        double correctAnswer=0;
        for (int queNum=1 ; queNum<=10 ; ++queNum){
            string question=generateQuestion(level);
            int answer=calculateAnswer(question);       
            cout<<"Question "<<queNum<<" : How much is "<<question<<" ? : ";
            int sanswer;
            while( !(cin>>sanswer)){
                cout<<"Invalid input!Enter a vaild integer :";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max() , '\n');
            }

            if (sanswer==answer){
                correctAnswer+=1;
                cout<<"Very good!"<<endl;
            }else{
                int attempt=1;
                while(attempt <3){
                    attempt+=1;
                    cout<<"No.Please try again : ";                  
                    while( !(cin>>sanswer)){
                    cout<<"Invalid input!Enter a vaild integer :";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max() , '\n');
                    }
                    if (sanswer==answer){
                        correctAnswer+=1;
                        cout<<"Very good!"<<endl;
                        break;
                    }                   

                }
            }
        }
        double percentage=correctAnswer/10*100;
        cout<<" After 10 questions : "<<endl;
        cout<<"Correct Answers : "<<correctAnswer<<endl;
        cout<<"Incorrect Answers : "<<10-correctAnswer<<endl;
        cout<<"Score : "<<percentage<<"%"<<endl;

        if (percentage<75){
            cout<<"Please ask your teacher for extra help."<<endl;
        }else{
            cout<<"Congradulations, you are ready to go to the next level!"<<endl;
        }
        
        cout<<"\n Do you wan to reset the program ? (y/n) :";
        char ans;
        cin>>ans;
        if (ans!='y' && ans!='Y'){
            break;
        }

        }

    }

