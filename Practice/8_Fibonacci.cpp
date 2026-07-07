// Using loop - Best Fibonacci implementation

#include <iostream>
using namespace std;

// TC: O(n), SC: O(1)

int Fibonacci(int n)
{
    int a = 0, b = 1, c;

    if (n <= 0)
        return a;

    cout << a << " ";

    for (int i = 1; i < n; i++)
    {
        cout << b << " ";
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}

int main()
{
    int n = 10;
    Fibonacci(n);

    return 0;
}