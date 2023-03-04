#include <iostream>
using namespace std;

int main()
{
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;
    double enterNum;
    int method, floorNum, ceilingNum, roundNum;

    cout << "Please enter a Real number:" << endl;
    cin >> enterNum;
    cout << "Choose your rounding method:" << endl;
    cout << "1. Floor round" << endl;
    cout << "2. Ceiling round" << endl;
    cout << "3. Round to the nearest whole number" << endl;
    cin >> method;

    if(enterNum == (int)enterNum)
    {
        // When enterNum is an interger, it's rounded results of the three methods are the same.
        ceilingNum = roundNum = floorNum = (int)enterNum;
    }
    else
    {
        if(enterNum > 0)
        {
            floorNum = (int)enterNum;
            ceilingNum = floorNum + 1;
        }
        else
        {
            ceilingNum = (int)enterNum;
            floorNum = ceilingNum - 1;
        }
        if((enterNum - floorNum) < 0.5)
            roundNum = floorNum;
        else
            roundNum = ceilingNum;
    }
    
    switch(method)
    {
        case FLOOR_ROUND:
            cout << floorNum << endl;
            break;
        case CEILING_ROUND:
            cout << ceilingNum << endl;
            break;
        case ROUND:
            cout << roundNum << endl;
            break;
    }
    return 0;
}
