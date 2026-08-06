// Minimum Sideways Jump - Leetcode 1824 (Approach: recursion + memorization)
// TC: O(n) where n is the length of the obstacles array
// SC: O(4xn) for dp array + O(n) for recursion stack ~ O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &obstacles, int currlane, int currpos, vector<vector<int>> &dp)
    {
        int n = obstacles.size() - 1;
        if (currpos == n)
            return 0;
        if (dp[currlane][currpos] != -1)
            return dp[currlane][currpos];

        if (obstacles[currpos + 1] != currlane)
            return solve(obstacles, currlane, currpos + 1, dp);
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (currlane != i && obstacles[currpos] != i)
                {
                    ans = min(ans, 1 + solve(obstacles, i, currpos, dp));
                }
            }
            dp[currlane][currpos] = ans;
            return dp[currlane][currpos];
        }
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        return solve(obstacles, 2, 0, dp);
    }
};

int main()
{
    Solution sol;
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << sol.minSideJumps(obstacles) << endl; // Output: 2
    return 0;
}