#include <bits/stdc++.h>
using namespace std;

int fibonacciNumber(int n)
{
    int a = 0, b = 1, ans;

    for (int i = 1; i < n - 1; i++)
    {
        ans = a + b;
        a = b;
        b = ans;
    }
    return ans;
}

int main()
{
    int ans = fibonacciNumber(10);

    cout << ans;
    return 0;
}