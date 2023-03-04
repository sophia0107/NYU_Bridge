#include <iostream>
#include <string>
using namespace std;

const char X = 'x';
const char SPACE = ' ';

bool isDigit(char c);
void replaceNum(string& str);
 
int main() {
    string text;
    cout << "Please enter a line of text:" << endl;
    getline(cin, text);
    replaceNum(text);
    cout << text << endl;
    return 0;
}

bool isDigit(char c) {
    if(c >= '0' && c <= '9')
        return true;
    else
        return false;
}

void replaceNum(string& str) {
    int beginInd, endInd;
    int i, j;
    do {
        beginInd = str.find(SPACE, i);
        endInd = str.find(SPACE, beginInd + 1);
        i = endInd;
        if(isDigit(str[beginInd + 1])) {
            if(endInd == string::npos || isDigit(str[endInd - 1])) {
                j = beginInd + 1;
                while(str[j] != SPACE) {
                    str[j] = X;
                    j++;
                }
            }
        }
    } while(endInd != string::npos);
}
