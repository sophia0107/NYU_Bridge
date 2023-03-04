#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_OF_DIGITS = 10;
const int PASSWORD_SIZE = 5;
const int ACTUAL_PIN = 12345;

void printArray(int arr[], int arrSize);
void generateArray(int arr[], int arrSize);
void convertToArray(int num, int arr[], int arrSize);

int main() {
    int pinArr[NUM_OF_DIGITS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int mappingArr[NUM_OF_DIGITS];
    int actualPIN[PASSWORD_SIZE];
    int userArr[PASSWORD_SIZE];
    int userPIN;
    int i, j;
    bool isMatching = true;

    cout << "Please enter your PIN according to the following mapping:" << endl;
    //Show PIN and it's corresponding numbers
    cout << "PIN: ";
    printArray(pinArr, NUM_OF_DIGITS);
    cout << "NUM: ";
    generateArray(mappingArr, NUM_OF_DIGITS);
    printArray(mappingArr, NUM_OF_DIGITS);

    //Input the response from the user
    cin >> userPIN;

    //Determine whether the user's reponse correctly matches the PIN number
    convertToArray(ACTUAL_PIN, actualPIN, PASSWORD_SIZE);
    convertToArray(userPIN, userArr, PASSWORD_SIZE);
    for(i = 0; i < PASSWORD_SIZE; i++) {
        for(j = 0; j < NUM_OF_DIGITS; j++) {
            if(actualPIN[i] == pinArr[j]) {
                if(userArr[i] != mappingArr[j]) {
                    isMatching = false;
                }
            }
        }
    }
    if(isMatching) {
        cout << "Your PIN is correct" << endl;
    }
    else {
        cout << "Your PIN is not correct" << endl;
    }
    return 0;
}

void printArray(int arr[], int arrSize) {
    int ind;

    for(ind = 0; ind < arrSize; ind++) {
        cout << arr[ind] << " ";
    }
    cout << endl;
}

void generateArray(int arr[], int arrSize) {
    int ind;

    srand(time(0));
    for(ind = 0; ind < arrSize; ind++) {
        arr[ind] = rand() % 10;
    }
}

void convertToArray(int num, int arr[], int arrSize) {
    int ind;

    for(ind = arrSize - 1; ind >= 0; ind--) {
        arr[ind] = num % 10;
        num /= 10;
    }
}
