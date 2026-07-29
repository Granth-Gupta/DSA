// Cut into segments - CN (Approach: Bottom Up DP)
// TC: O(n) SC: O(n)

// Note: Here space optimization is not possible as [x,y,z] are not fixed and can be any value.
// So we need to store the previous values in dp array to calculate the current value.

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }

    if (dp[n] < 0)
        return 0;
    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    return solve(n, x, y, z);
}

int main()
{
    int n, x, y, z;

    cin >> n;

    x = 5;
    y = z = 2;

    cout << cutSegments(n, x, y, z) << endl;

    return 0;
}