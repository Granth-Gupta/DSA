// Minumum Score triangulation of polygon - LeetCode 1039 (Approach-4: Gap Strategy)
// TC: O(n^3) SC: O(n^2) (Bottom-Up DP with Gap Strategy)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // g is the gap between index i and index j (g = j - i)
        for (int g = 2; g < n; ++g)
        {
            for (int i = 0; i < n - g; ++i)
            {
                int j = i + g;
                dp[i][j] = INT_MAX;

                // Try all intermediate vertices k between i and j
                for (int k = i + 1; k < j; ++k)
                {
                    int triangle_cost = values[i] * values[k] * values[j];
                    int total_cost = dp[i][k] + dp[k][j] + triangle_cost;

                    dp[i][j] = min(dp[i][j], total_cost);
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> values = {1, 2, 3, 4};
    cout << sol.minScoreTriangulation(values) << endl;

    return 0;
}