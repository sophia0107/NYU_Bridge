#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
 
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
 
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
 
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
 
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
 
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
 
    return 0;
}

void reverseArray(int arr[], int arrSize) {
    int ind;
    for(ind = 0; ind < arrSize / 2; ind++) {
        swap(arr[ind], arr[arrSize - 1 - ind]);
    }
}

void removeOdd(int arr[], int& arrSize) {
    int curr = 0;
    int ind;
    for(ind = 0; ind < arrSize; ind++) {
        if(arr[ind] % 2 == 0) {
            arr[curr] = arr[ind];
            curr++;
        }
    }
    arrSize = curr;
}

void splitParity(int arr[], int arrSize) {
    int i = 0;
    int j = arrSize - 1;
    int x, y;

    while(i <= j) {
        x = arr[i] % 2;
        y = arr[j] % 2;
        if(x != 0 && y == 0) {
            i++;
            j--;
        }
        else if(x == 0 && y != 0) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else if(x != 0 && y != 0) {
            i++;
        }
        else {
            j--;
        }
    }
}

void printArray(int arr[], int arrSize) {
    int i;
 
    for (i = 0; i < arrSize; i++) {
    cout<<arr[i]<<' ';
    }
    cout<<endl;
}
