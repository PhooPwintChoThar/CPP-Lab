#include<iostream>
#include<sstream>
#include<random>
using namespace std;

int number1;
int number2;
char operand;

string generateQuestion(int level){
    int num1, num2;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis;

    switch (level){
        case 1:
            num1 = dis(gen) % 10; 
            num2 = dis(gen) % 10; 
            break;

        case 2:
            num1 = dis(gen) % 90 + 10; 
            num2 = dis(gen) % 90 + 10; 
            break;

        case 3:
            num1 = dis(gen) % 900 + 100; 
            num2 = dis(gen) % 900 + 100; 
            break;

        default:
            return "Invalid level";
    }

    int x = dis(gen) % 3;
    switch (x){
        case 0:
            operand = '+';
            break;

        case 1:
            operand = '-';
            break;

        case 2:
            operand = '*';
            break;
    }

    number1 = num1;  // Update global number1
    number2 = num2;  // Update global number2

    return to_string(num1) + " " + operand + " " + to_string(num2);
}

bool isDigit(string s){
    istringstream iss(s);
    int a;
    iss >> a;
    return iss.eof() && !iss.fail();
}

int cal_answer(){
    switch (operand){
        case '+':
        return number1 + number2;

        case '-':
        return number1 - number2;

        case '*':
        return number1 * number2;
    }
}

int main(){
    while (true){
        double questions = 0;
        double correctedAnswer = 0;
        cout << "\nDifficulty Level (1-3): ";
        string difficulty;
        cin >> difficulty;
         int level = stoi(difficulty);
        if (!isDigit(difficulty) || level<=0 || level>3 ){
            cout << "\nInvalid level!\n";
            continue;
        }

      

        while (questions != 10.0){
            string question = "How much is ";
            string generatedQuestion = generateQuestion(level);
            question += generatedQuestion;
            cout << "Question: " << question << "?" << endl;
            int answer;
            cout << "Answer: ";
            cin >> answer;

            int c_answer = cal_answer();
            string c = to_string(answer);

            while (!isDigit(c)){
                cout << "\nYou must enter digits. Type again: ";
                cin >> answer;
            }

            int attempt = 0;
            if (answer == c_answer){
                cout << "\nVery good!\n";
                correctedAnswer += 1.0;
            } else {
                while (attempt != 2){
                    attempt += 1;
                    cout << "\nNo, Please try again. Answer: ";
                    cin >> answer;
                    if (c_answer == answer){
                        correctedAnswer += 1.0;
                        break;
                    }
                }
            }
            questions += 1.0;
        }

        cout << "\nAfter 10 questions:\n";
        cout << "Correct Answers: " << correctedAnswer << endl;
        cout << "Incorrect Answers: " << 10 - correctedAnswer << endl;
        int score = correctedAnswer / questions * 100;
        cout << "\nScore: " << score << "%";
        if (score < 75){
            cout << "\nPlease ask our teacher for help.";
        } else {
            cout << "Congratulations, you are ready to go to the next level.";
        }

        string reset;
        cout << "\nDo you want to try again? (y/n): ";
        cin >> reset;
        if (reset == "n" || reset == "N"){
            break;
        }
    }
}
