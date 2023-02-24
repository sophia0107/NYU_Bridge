#include <iostream>
#include <string>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
string printHeader(int year, int month, int& numOfDays);
bool isLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main() {
    int year, startingDay;

    cout << "Please enter the year (e.g. 2016):" << endl;
    cin >> year;
    cout << "Plear enter the starting day of that year (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.):" << endl;
    cin >> startingDay;
    cout << "The formatted yearly calender of the year " << year << " is as follows:" << endl;
    printYearCalender(year, startingDay);
    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
    int i;
    int day = 1; // The current day
    int lastDayInWeek; // A number 1-7 that represents the day in the week of the last day in that month
    
    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;
    for(i = 1; i < (numOfDays + startingDay); i++) {
        if(i < startingDay) {
            cout << '\t';
        }
        else {
            cout << day << '\t';
            day++;
            if(i % 7 == 0) {
                cout << endl;
            }
        }
    }
    lastDayInWeek = (i - 1) % 7;
    return lastDayInWeek;
}

string printHeader(int year, int month, int& numOfDays) {
    string header;

    switch(month) {
        case 1:
            header = "January";
            numOfDays = 31;
            break;
        case 2:
            header = "Fabruary";
            if(isLeapYear(year)) {
                numOfDays = 29;
            }
            else {
                numOfDays = 28;
            }
            break;
        case 3:
            header = "March";
            numOfDays = 31;
            break;
        case 4:
            header = "April";
            numOfDays = 30;
            break;
        case 5:
            header = "May";
            numOfDays = 31;
            break;
        case 6:
            header = "June";
            numOfDays = 30;
            break;
        case 7:
            header = "July";
            numOfDays = 31;
            break;
        case 8:
            header = "August";
            numOfDays = 31;
            break;
        case 9:
            header = "September";
            numOfDays = 30;
            break;
        case 10:
            header = "October";
            numOfDays = 31;
            break;
        case 11:
            header = "November";
            numOfDays = 30;
            break;
        case 12:
            header = "December";
            numOfDays = 31;
            break;
    }
    return header;
}

bool isLeapYear(int year) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

void printYearCalender(int year, int startingDay) {
    int month, numOfDays;

    for(month = 1; month <= 12; month++) {
        cout << printHeader(year, month, numOfDays) << ' ' << year << endl;
        startingDay = printMonthCalender(numOfDays, startingDay) + 1;
        // Ensure there is a whitespace between the calendar of two months
        if(startingDay != 1) {
            cout << endl;
        }
        cout << endl;
    }
}
