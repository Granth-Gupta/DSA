#include <iostream>
#include <vector>
using namespace std;

// TC: O(n)
// SC: O(n) + O(n) for recursion stack ~ O(n)

int fibonacci(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);

    return dp[n];
}

int main()
{
    int n = 5;

    vector<int> dp(n + 1, -1);

    fibonacci(n, dp);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 0; i <= n; i++)
    {
        cout << "F(" << i << ") = " << dp[i] << endl;
    }

    return 0;
}