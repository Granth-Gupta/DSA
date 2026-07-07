#include <iostream>
using namespace std;

// TC: O(n), SC: O(n)

void fibonacci(int a, int b, int n)
{
    if (n == 0)
        return;

    cout << a << " ";

    fibonacci(b, a + b, n - 1);
}

int main()
{
    int n = 10;
    fibonacci(0, 1, n);

    return 0;
}