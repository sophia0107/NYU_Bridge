#include <iostream>
using namespace std;

double eApprox(int n);

int main() {
    cout.precision(30);

    for(int n = 1; n <= 15; n++) {
        cout << "n = " << n << '\t' << eApprox(n) << endl;
    }
    return 0;
}

double eApprox(int n) {
    int i;
    double e = 1.0;
    double factorial = 1.0;
    
    for(i = 1; i <= n; i++) {
        factorial *= i;
        e += 1.0/factorial;
    }
    return e;
}
