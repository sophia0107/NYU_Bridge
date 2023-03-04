#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName, middleInitial, lastName;

    cout << "Please enter your name in the following format:" << endl;
    cout << "first name, then middle name or initial, and then last name (e.g. Mary Average User)" << endl;
    cin >> firstName >> middleInitial >> lastName;
    cout << "Your name in the following format: Last_Name, First_Name Middle_Initial. (e.g. User, Mary A.) is:" << endl;
    cout << lastName << ", " << firstName << " " << middleInitial[0] << "." << endl;
    return 0;
}
