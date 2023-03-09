#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {
    int arr[6] = {5, 2, 11, 7, 6, 4};
    cout << "The original array is:" << endl;
    printArray(arr, 6);
    cout << "The reordered elements of the array are:" << endl;
    oddsKeepEvensFlip(arr, 6);
    printArray(arr, 6);
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int oddsCount = 0;
    int evensCount = 0;
    int* temp = new int [arrSize];

    for(int i = 0; i < arrSize; i++) {
        if(arr[i] % 2 == 0) {
            temp[arrSize - evensCount - 1] = arr[i];
            evensCount++;
        }
        else {
            temp[oddsCount] = arr[i];
            oddsCount++;
        }
    }
    for(int i = 0; i < arrSize; i++) {
        arr[i] = temp[i];
    }
    delete[] temp;
    temp = NULL;
}

void printArray(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
