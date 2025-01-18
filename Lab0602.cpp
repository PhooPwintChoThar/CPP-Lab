#include<iostream>
#include<fstream>
#include<vector>
#include<random>
using namespace std;

string generateRandomWord(const vector<string> &words){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> randomInt(0 , words.size()-1);
    
    return words[randomInt(gen)];
}

string scrambleWord(string word){
        random_device rd;
        mt19937 gen(rd()); 
        uniform_int_distribution<int> randomInt(0 , word.size()-1);

        for(size_t c=0 ; c<word.size() ; ++c){
        char temp=word[c];
        int randomIndex=randomInt(gen);
        word[c]=word[randomIndex];
        word[randomIndex]=temp;
        }

        return word;
}


int main(){
    ifstream file("word.txt");

    if(!file){
        cerr<<"Error : failed to open the file!"<<endl;
        return 1;
    }

    cout<<"File opened successfully!"<<endl;
    vector<string> words;
    string word;
    while( getline(file , word)){
        words.push_back(word);
    }
    cout<<"Words added successfully!"<<endl;

    //Game start

    int wordsPlayed=0;
    int correctAnswers=0;
    int wrongAttempts=0;

    cout<<"Welcome to Word Jumble Game!"<<endl;

    for(int word=1 ; word<=5 ; ++word){

        cout<<"Word "<<word<<"/5"<<endl;
        string randomWord= generateRandomWord(words);
        string scrambledWord=scrambleWord(randomWord);
        wordsPlayed+=1;

        int attempt=1;       
        while(attempt<=3){
            cout<<"Scrambled Word : "<<scrambledWord<<endl;
            string ans;
            cout<<"Your guess (or 'next' to skip , 'quit' to exit) : ";
            cin>>ans;
            if(ans==randomWord){
                correctAnswers+=1;
                cout<<"Correct!!***"<<endl;
                break;
            }else if(ans=="next"){
                break;
            }else if(ans=="quit"){
                cout<<"Exiting from the program..."<<endl;
                cout<<"Words played : "<<wordsPlayed<<endl;
                cout<<"Correct answer : "<<correctAnswers<<endl;
                cout<<"Wrong attempts : "<<wrongAttempts<<endl;
                file.close();
                return 1;
            }else{
                wrongAttempts+=1;
                cout<<"Wrongs!"<<(3-attempt)<<" attempts left."<<endl;
            }
            attempt+=1;
        }
        
    }

    cout<<"Game completed! Here's your summary : "<<endl;
    cout<<"Words played : "<<wordsPlayed<<endl;
    cout<<"Correct answer : "<<correctAnswers<<endl;
    cout<<"Wrong attempts : "<<wrongAttempts<<endl;

    file.close();
    return 0;

}

