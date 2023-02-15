#include <iostream>
using namespace std;

int fib(int& n);
int main()
{
    int num, fn;
    cout << "Please enter a positive integer: ";
    cin >> num;
    fn = fib(num);
    cout << fn << endl;
    return 0;
}

int fib(int& n)
{
    int f1 = 1;
    int f2 = 1;
    int i;
    for(i = 2; i < n; i++)
    {
        f1 = f1 + f2;
        swap(f1, f2);
    }
    return f2;
}
