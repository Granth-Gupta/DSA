#include <iostream>
using namespace std;

int factorial(int a)
{
    if (a == 0 || a == 1)
        return 1;
    int val = factorial(a - 1);
    return val * a;
}

int main()
{
    int a = 5;

    int result = factorial(a);
    cout << result;

    return 0;
}