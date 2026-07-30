// Count Derangements - CN (Approach 2: Top Down DP)
// TC: O(n) SC: O(n) (Recursion stack space + DP array space)

#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

long long int solve(int n, vector<long long int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = ((n - 1) % MOD) * ((solve(n - 2, dp) % MOD) + (solve(n - 1, dp) % MOD)) % MOD;

    return dp[n];
}

long long int countDerangements(int n)
{
    vector<long long int> dp(n + 1, -1);
    return solve(n, dp);
}

int main()
{
    int n;
    cin >> n;
    cout << countDerangements(n) << endl;
    return 0;
}
