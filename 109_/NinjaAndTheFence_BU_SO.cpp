// Ninja and the Fence - CN (Approach 4: Bottom-Up DP + Space Optimization)
// TC: O(n) SC: O(1)

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
    int prev2 = k;
    int prev1 = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        int ans = mul(k - 1, add(prev2, prev1));
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
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