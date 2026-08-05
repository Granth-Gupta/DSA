// Minumum Score triangulation of polygon - LeetCode 1039 (Approach-2: Recursion + Memoization)
// TC: O(n^3) SC: O(n^2) + O(n) (Recursion + Recursion Stack)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &v, int i, int j, vector<vector<int>> &dp)
    {
        if (i + 1 == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, v[i] * v[j] * v[k] + solve(v, i, k, dp) + solve(v, k, j, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(values, 0, n - 1, dp);
    }
};

int main()
{
    Solution sol;
    vector<int> values = {1, 2, 3, 4};
    cout << sol.minScoreTriangulation(values) << endl;

    return 0;
}