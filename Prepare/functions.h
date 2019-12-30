//
// Created by mph on 30.12.19.
//
#ifndef PREPARE_FUNCTIONS_H
#define PREPARE_FUNCTIONS_H
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string getLine();
int getNumber();
vector<string> getWords(const string &);
void printVector(const vector<string>&);
void recurs(const vector<string>& resultWords, vector<string> deltaWords, int num);

#endif //PREPARE_FUNCTIONS_H
