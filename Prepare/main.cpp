#include "functions.h"

int main() {
    string mLine = getLine();
    int num = getNumber();
    vector<string> mWords = getWords(mLine);
    vector<string> mList;
    recurs(mList, mWords, num);
    return 0;
}