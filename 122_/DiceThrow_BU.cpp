// Dice Throw Problem - GFG (Approach: Bottom-Up Dynamic Programming)
// TC: O(n * x * m) SC: O(n * x)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int m, int n, int x)
    {
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= x; j++)
            {
                int ans = 0;
                for (int k = 1; k <= m && j - k >= 0; k++)
                {
                    ans += dp[i - 1][j - k];
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][x];
    }

public:
    int noOfWays(int m, int n, int x)
    {
        return solve(m, n, x);
    }
};

int main()
{
    int m = 6, n = 3, x = 12;
    Solution obj;
    cout << obj.noOfWays(m, n, x) << endl;
    return 0;
}