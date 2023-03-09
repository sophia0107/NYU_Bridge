#include <iostream>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

void countLetters(string text, int arr[], int size);
bool areAnagrams(int arr1[], int arr2[], int size);

int main() {
    string s1, s2;
    int alphabet1[ALPHABET_SIZE] = {0};
    int alphabet2[ALPHABET_SIZE] = {0};
    
    cout << "Please enter the first string:" << endl;
    getline(cin, s1);
    cout << "Please enter the second string:" << endl;
    getline(cin, s2);
    countLetters(s1, alphabet1, ALPHABET_SIZE);
    countLetters(s2, alphabet2, ALPHABET_SIZE);
    if(areAnagrams(alphabet1, alphabet2, ALPHABET_SIZE)) {
        cout << "The two strings are anagrams." << endl;
    }
    else {
        cout << "The two strings are not anagrams." << endl;
    }
    return 0;
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

bool areAnagrams(int arr1[], int arr2[], int size) {
    bool areAnagrams = true;
    for(int i = 0; i < size; i++) {
        if(arr1[i] != arr2[i]) {
            areAnagrams = false;
            break;
        }
    }
    return areAnagrams;
}
