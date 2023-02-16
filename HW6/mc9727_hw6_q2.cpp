#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {
    int n;
    char symbol;

    cout << "Please enter the number of triangles in the tree: ";
    cin >> n;
    cout << "Please enter the character filling the tree: ";
    cin >> symbol;
    printPineTree(n, symbol);
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    int i, j;
    char space = ' ';
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= (m+n-i); j++) {
            cout << space;
        }
        for(j = 1; j <= (2*i-1); j++) {
            cout << symbol;
        }
        cout << endl;
    }
}

void printPineTree(int n, char symbol) {
    int k;
    for(k = 1; k <= n; k++) {
        printShiftedTriangle(k+1, n-k, symbol);
    }
}
