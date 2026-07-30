// Count Derangements - CN (Approach 3: Bottom Up DP)
// TC: O(n) SC: O(n) (DP array space)

#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

long long int solve(int n)
{
    vector<long long int> dp(n + 1, -1);
    dp[1] = 0;
    dp[2] = 1;

    if (n == 1 || n == 2)
        return dp[n];

    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((i - 1) % MOD) * ((dp[i - 2] % MOD) + (dp[i - 1] % MOD)) % MOD;
    }

    return dp[n];
}

long long int countDerangements(int n)
{
    return solve(n);
}

int main()
{
    int n;
    cin >> n;
    cout << countDerangements(n) << endl;
    return 0;
}
