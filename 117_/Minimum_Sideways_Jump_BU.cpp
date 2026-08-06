// Minimum Sideways Jump - Leetcode 1824 (Approach: Bottom Up DP)
// TC: O(n) where n is the length of the obstacles array
// SC: O(4xn) for dp array ~ O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &obstacles)
    {
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(4, vector<int>(n + 1, 1e9)); // INT_MAX can cause overflow in some cases, so we use 1e9 instead

        for (int i = 0; i <= 3; i++)
            dp[i][n] = 0;

        for (int currpos = n - 1; currpos >= 0; currpos--)
        {
            for (int currlane = 1; currlane <= 3; currlane++)
            {
                if (obstacles[currpos + 1] != currlane)
                    dp[currlane][currpos] = dp[currlane][currpos + 1];
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (currlane != i && obstacles[currpos] != i)
                        {
                            // ans = min(ans, 1 + dp[i][currpos]); -> Wrong as dp[i][currpos] is still 1e9
                            // Since, dp[i][currpos] comes from dp[i][currpos+1] (As we are using bottom up approach)

                            ans = min(ans, 1 + dp[i][currpos + 1]);
                        }
                    }
                    dp[currlane][currpos] = ans;
                }
            }
        }
        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {
        return solve(obstacles);
    }
};

int main()
{
    Solution sol;
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << sol.minSideJumps(obstacles) << endl; // Output: 2
    return 0;
}