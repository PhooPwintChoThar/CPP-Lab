#include<iostream>
#include<random>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

string generateRandomWord(vector<string> &words) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> randomInt(0, words.size() - 1);
    string randomWord = words[randomInt(gen)];
    return randomWord;
}

string Scrambling(string randomWord) {
    random_device rd;
    mt19937 gen(rd());
    for (size_t n = randomWord.size() - 1; n > 0; --n) {
        uniform_int_distribution<size_t> size(0, n - 1);
        size_t j = size(gen);
        char temp = randomWord[n];
        randomWord[n]= randomWord[j];
        randomWord[j]=temp;

    }
    return randomWord;
}

int main() {
    ifstream file("word.txt");
    if (!file) {
        cerr << "Error: unable to open the file!" << endl;
        return 1;
    }

    cout << "File opened successfully.\n";

    vector<string> words;
    string line;

    while (getline(file, line)) {
        words.push_back(line);
    }

    int attempt;
    int correctAnswer = 0;
    int wrongAttempts = 0;
    string randomWord;
    int wordsPlayed = 0;

    cout << "Welcome to Word Jumble Game\n";

    for (int time = 1; time <= 5; ++time) {
        attempt = 1;
        cout << "Word " << time << " / 5" << endl;
        randomWord = generateRandomWord(words);
        string scrambledWord = Scrambling(randomWord);
        cout << "Scrambled word: " << scrambledWord << endl;

        while (attempt <= 3) {
            cout << "Your guess (or 'next' to skip, 'quit' to exit): ";
            string answer;
            cin >> answer;

            if (answer == randomWord) {
                cout << "Correct!\n";
                correctAnswer += 1;
                wordsPlayed += 1;
                break;
            } else if (answer == "next") {
                wordsPlayed += 1;
                break;
            } else if (answer == "quit") {
                cout << "Words played = " << wordsPlayed << endl;
                cout << "Correct answers = " << correctAnswer << endl;
                cout << "Wrong attempts = " << wrongAttempts << endl;
                file.close();
                cout << "File reading completed.\n";
                return 0;
            } else {
                cout << "Wrong! " << (3 - attempt) << " attempt(s) left\n";
                attempt++;
                wrongAttempts += 1;
            }
        }

        if (wordsPlayed >= 5) break;
    }

    cout << "Words played = " << wordsPlayed << endl;
    cout << "Correct answers = " << correctAnswer << endl;
    cout << "Wrong attempts = " << wrongAttempts << endl;

    file.close();
    cout << "File reading completed.\n";
    return 0;
}
