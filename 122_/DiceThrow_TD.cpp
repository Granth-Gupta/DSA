// Dice Throw Problem - GFG (Approach: Recursion with Memoization)
// TC: O(n * x * m) SC: O(n * x) + O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int faces, int dice, int target, vector<vector<int>> &dp)
    {
        if (target < 0 || (target != 0 && dice == 0) || (target == 0 && dice != 0))
            return 0;
        if (target == 0 && dice == 0)
            return 1;
        if (dp[dice][target] != -1)
            return dp[dice][target];

        int ans = 0;
        for (int i = 1; i <= faces; i++)
        {
            ans = ans + solve(faces, dice - 1, target - i, dp);
        }
        dp[dice][target] = ans;
        return dp[dice][target];
    }

public:
    int noOfWays(int m, int n, int x)
    {
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
        return solve(m, n, x, dp);
    }
};

int main()
{
    int m = 6, n = 3, x = 12;
    Solution obj;
    cout << obj.noOfWays(m, n, x) << endl;
    return 0;
}