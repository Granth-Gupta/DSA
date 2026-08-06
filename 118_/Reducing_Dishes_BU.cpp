// Reducing Dishes - Leetcode 1402 (Approach: Bottom-Up DP)
// TC: O(n^2) | SC: O(n^2) - DP Array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
                int exclude = 0 + dp[index + 1][time];

                dp[index][time] = max(include, exclude);
            }
        }

        return dp[0][0];
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());

        return solve(satisfaction);
    }
};

int main()
{
    Solution solution;
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout << solution.maxSatisfaction(satisfaction) << endl; // Output: 14
    return 0;
}