// Ninja and the Fence - CN (Approach 2: Recursion + Memoization)
// TC: O(n) SC: O(n) (Recursion stack space + dp array)

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int add(int a, int b)
{
    return ((a) % MOD + (b) % MOD) % MOD;
}

int mul(int a, int b)
{
    // 1LL is used to convert the result of (a) % MOD to long long to avoid integer overflow during multiplication
    return ((a) % MOD * 1LL * (b) % MOD) % MOD;
}

int solve(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;
    if (n == 2)
        return add(k, mul(k, k - 1));

    if (dp[n] != -1)
        return dp[n];

    dp[n] = mul(k - 1, add(solve(n - 2, k, dp), solve(n - 1, k, dp)));

    return dp[n];
}

int numberOfWays(int n, int k)
{
    vector<int> dp(n + 1, -1);
    return solve(n, k, dp);
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << numberOfWays(n, k) << endl;
    return 0;
}
