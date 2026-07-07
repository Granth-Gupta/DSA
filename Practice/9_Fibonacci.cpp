// To avoid large value output use 10^9 + 7 modulus

#include <bits/stdc++.h>
using namespace std;

int fibonacciNumber(int n)
{
    int a = 0, b = 1, ans;

    if (n == 0 || n == 1)
        return n;

    for (int i = 1; i < n; i++)
    {
        ans = (a + b) % 1000000007;
        a = b;
        b = ans;
    }

    return ans;
}

int main()
{
    int n = 10;
    cout << "Fibonacci number at position " << n << " is: " << fibonacciNumber(n) << endl;

    return 0;
}