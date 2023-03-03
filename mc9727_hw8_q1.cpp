#include <iostream>
#include <string>
using namespace std;

const int NUM_OF_INTEGERS = 20;
int minInArray(int arr[], int arrSize);
string indicesOfMinInArray(int arr[], int arrSize, int minValue);

int main() {
    int arr[NUM_OF_INTEGERS];
    int minValue;
    string minIndices;
    int ind;

    cout << "Please enter 20 integers separated by a space:" << endl;
    for(ind = 0; ind < NUM_OF_INTEGERS; ind++) {
        cin >> arr[ind];
    }
    minValue = minInArray(arr, NUM_OF_INTEGERS);
    cout << "The minimum value is " << minValue << ", ";
    minIndices = indicesOfMinInArray(arr, NUM_OF_INTEGERS, minValue);
    cout << "and it is located in the following indices: " << minIndices;
    return 0;
}

int minInArray(int arr[], int arrSize) {
    int minValue = arr[0];
    int ind;

    for(ind = 0; ind < arrSize; ind++) {
        if(arr[ind] < minValue) {
            minValue = arr[ind];
        }
    }
    return minValue;
}

string indicesOfMinInArray(int arr[], int arrSize, int minValue) {
    string minIndices = "";
    int ind;

    for(ind = 0; ind < arrSize; ind++) {
        if(arr[ind] == minValue) {
            minIndices += to_string(ind) + " ";
        }
    }
    return minIndices;
}
