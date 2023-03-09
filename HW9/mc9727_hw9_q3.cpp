#include <iostream>
using namespace std;

int* getPosNum1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNum2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNum3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNum4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printArray(int* arr, int arrSize);

int main() {
    int arrSize = 6;
    int arr[arrSize] = {3, -1, -3, 0, 6, 4};
    cout << "The original array is:" << endl;
    printArray(arr, arrSize);
    cout << "The new array containing only the positive numbers is:" << endl;

    cout << "Version1: ";
    int* outPosArr1;
    int outPosArr1Size;
    outPosArr1 = getPosNum1(arr, arrSize, outPosArr1Size);
    printArray(outPosArr1, outPosArr1Size);
    delete[] outPosArr1;
    outPosArr1 = NULL;

    cout << "Version2: ";
    int* outPosArr2;
    int outPosArr2Size;
    outPosArr2 = getPosNum2(arr, arrSize, &outPosArr2Size);
    printArray(outPosArr2, outPosArr2Size);
    delete[] outPosArr2;
    outPosArr2 = NULL;

    cout << "Version3: ";
    int* outPosArr3 = new int [arrSize];
    int outPosArr3Size;
    getPosNum3(arr, arrSize, outPosArr3, outPosArr3Size);
    printArray(outPosArr3, outPosArr3Size);
    delete[] outPosArr3;
    outPosArr3 = NULL;

    cout << "Version4: ";
    int* outPosArr4 = new int [arrSize];
    int outPosArr4Size;
    getPosNum4(arr, arrSize, &outPosArr4, &outPosArr4Size);
    printArray(outPosArr4, outPosArr4Size);
    delete[] outPosArr4;
    outPosArr4 = NULL;
    return 0;
}

int* getPosNum1(int* arr, int arrSize, int& outPosArrSize) {
    int* outPosArr = new int [arrSize];
    int count = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            outPosArr[count++] = arr[i];
        }
    }
    outPosArrSize = count;
    return outPosArr;
}

int* getPosNum2(int* arr, int arrSize, int* outPosArrSizePtr) {
    int* outPosArr = new int [arrSize];
    int count = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            outPosArr[count++] = arr[i];
        }
    }
    *outPosArrSizePtr = count;
    return outPosArr;
}

void getPosNum3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    int count = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            outPosArr[count++] = arr[i];
        }
    }
    outPosArrSize = count;
}

void getPosNum4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    int count = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            (*outPosArrPtr)[count++] = arr[i];
        }
    }
    *outPosArrSizePtr = count;
}

void printArray(int* arr, int arrSize) {
    cout << "[";
    for(int i = 0; i < arrSize - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[arrSize - 1] << "]" << endl;
}
