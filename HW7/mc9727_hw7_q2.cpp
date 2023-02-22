#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {
    int M, i;
    int outCountDivs_1, outSumDivs_1;
    int outCountDivs_2, outSumDivs_2;
    string perfectNums = "";
    string amicableNums = "";

    cout << "Please enter a positive integer M (>= 2): ";
    cin >> M;
    for(i = 2; i <= M; i++) {
        if(isPerfect(i)) {
            perfectNums += (to_string(i) + " ");
        }
        else {
            analyzeDividors(i, outCountDivs_1, outSumDivs_1);
            if(i < outSumDivs_1 && outSumDivs_1 >= 2 && outSumDivs_1 <= M) {
                analyzeDividors(outSumDivs_1, outCountDivs_2, outSumDivs_2);
                if(outSumDivs_2 == i) {
                    amicableNums += (to_string(i) + " and " + to_string(outSumDivs_1) + '\n');
                }
            }
        }
    }
    cout << "All the perfect number between 2 and " << M << " are:" << endl;
    cout << perfectNums << endl;
    cout << "All pairs of amicable numbers that are between 2 and " << M << " are:" << endl;
    cout << amicableNums << endl;
    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
    int i;
    outCountDivs = outSumDivs = 1;
    for(i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            if(i == sqrt(num)) {
                outSumDivs += i;
                outCountDivs++;
            }
            else {
                outSumDivs += (i + num / i);
                outCountDivs += 2;
            }
        }
    }
}

bool isPerfect(int num) {
    int outCountDivs, outSumDivs;
    analyzeDividors(num, outCountDivs, outSumDivs);
    return (num == outSumDivs);
}
