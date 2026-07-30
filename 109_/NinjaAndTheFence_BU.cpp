// Ninja and the Fence - CN (Approach 3: Bottom-Up DP)

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int add(int a, int b)
{
    return ((a) % MOD + (b) % MOD) % MOD;
}

int mul(int a, int b)
{
    return ((a) % MOD * 1LL * (b) % MOD) % MOD;
}

int solve(int n, int k)
{
    vector<int> dp(n + 1, -1);

    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        dp[i] = mul(k - 1, add(dp[i - 2], dp[i - 1]));
    }

    return dp[n];
}

int numberOfWays(int n, int k)
{
    return solve(n, k);
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << numberOfWays(n, k) << endl;
    return 0;
}