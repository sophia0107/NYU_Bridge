#include <iostream>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;
const char SPACE = ' ';
const char PERIOD = '.';
const char COMMA = ',';

int countWords(string text);
void countLetters(string text, int arr[], int size);

int main() {
    string text;
    int wordsNum;
    int alphabet[ALPHABET_SIZE] = {0};
    char letter;

    cout << "Please enter a line of text:" << endl;
    getline(cin, text);
    wordsNum = countWords(text);
    cout << wordsNum << '\t' << "words" << endl;
    countLetters(text, alphabet, ALPHABET_SIZE);
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(alphabet[i] != 0) {
            cout << alphabet[i] << '\t';
            letter = 'a' + i;
            cout << letter << endl;
        }
    }
}

int countWords(string text) {
    int count = 1;
    for(int i = 0; i < text.length(); i++) {
        if(text[i] == SPACE) {
            count++;
        }
    }
    return count;
}

void countLetters(string text, int arr[], int size) {
    int index;
    for(int i = 0; i < text.length(); i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            index = text[i] - 'a';
            arr[index]++;
        }
        else if(text[i] >= 'A' && text[i] <= 'Z') {
            index = text[i] - 'A';
            arr[index]++;
        }
    }
}
