#include <iostream>
using namespace std;

// TC: O(2^n), SC: O(n)

int Fibonacci(int n)
{
    // Base case
    if (n <= 1)
        return n;

    // Recursive case
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        cout << Fibonacci(i) << " ";
    }

    return 0;
}