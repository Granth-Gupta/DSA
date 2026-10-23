#include <iostream>
using namespace std;

int fib(int n)
{
    if (n < 2)
        return n;

    int a = 0;
    int b = 1;
    int sum = 0;

    for (int i = 2; i < n; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }

    sum = a + b;

    return sum;
}

int main()
{
    int result = fib(10);

    cout << result << endl;

    return 0;
}