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
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << fibonacci(n, dp);

    return 0;
}