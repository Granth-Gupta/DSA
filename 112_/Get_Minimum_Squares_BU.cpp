// Get Minimum Squares - GFG - Approach 3 (Tabulation)
// TC: O(n * sqrt(n)), SC: O(n)

// Note: Space Optimization is not possible here as dp[i] depends on dp[i - j*j] where j*j can be any perfect square less than i, so we cannot reduce the space to O(sqrt(n)) or O(1).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solveTab(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                int temp = j * j;
                if (dp[i - temp] >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - temp]);
            }
        }
        return dp[n];
    }

public:
    int minSquares(int n)
    {
        return solveTab(n);
    }
};

int main()
{
    int n;
    cin >> n;
    Solution ob;
    cout << ob.minSquares(n) << endl;
    return 0;
}