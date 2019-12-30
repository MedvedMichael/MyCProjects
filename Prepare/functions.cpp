//
// Created by mph on 30.12.19.
//
#include "functions.h"
using namespace std;

string getLine() {
    string line;
    cout << "Input your array: ";
    getline(cin, line);
    return line;
}

int getNumber() {
    int num = 1;
    cout << "Input number n: ";
    cin >> num;
    return num;
}

vector<string> getWords(const string &text) {
    vector<string> words;
    string token;
    istringstream tokenStream(text);
    while (getline(tokenStream, token, ' '))
        if (!token.empty())
            words.push_back(token);
    return words;
}

void printVector(const vector<string> &words) {
    for (const auto &word : words)
        cout << word << " ";
    cout << endl;
}

void recurs(const vector<string> &resultWords, vector<string> deltaWords, int num) {
    if (resultWords.size() == num)
        printVector(resultWords);
    else {
        for (int i = 0; i < deltaWords.size(); i++) {
            vector<string> nextResultWords = resultWords;
            nextResultWords.push_back(deltaWords[i]);
            vector<string> nextDeltaWords = deltaWords;
            for (int j = 0; j <= i; j++)
                nextDeltaWords.erase(nextDeltaWords.begin());
            recurs(nextResultWords, nextDeltaWords, num);
        }
    }
}