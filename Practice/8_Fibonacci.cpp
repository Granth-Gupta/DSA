// Using loop - Much better Fibonacci implementation

#include <iostream>
using namespace std;

// TC: O(n), SC: O(1)

void Fibonacci(int n)
{
    int a = 0, b = 1, c;

    cout << a << " ";

    for (int i = 1; i < n; i++)
    {
        cout << b << " ";
        c = a + b;
        a = b;
        b = c;
    }
}

int main()
{
    int n = 10;
    Fibonacci(n);

    return 0;
}