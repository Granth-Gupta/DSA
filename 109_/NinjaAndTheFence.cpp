// Ninja and the Fence - CN (Approach 1: Recursion)
// TC: O(2^n) SC: O(n) (Recursion stack space)

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int add(int a, int b)
{
    return ((a) % MOD + (b) % MOD) % MOD;
}

int mul(int a, int b)
{
    return ((a) % MOD * (b) % MOD) % MOD;
}

int solve(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return add(k, mul(k, k - 1));

    int ans = mul(k - 1, add(solve(n - 2, k), solve(n - 1, k)));

    return ans;
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