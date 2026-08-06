// Reducing Dishes - Leetcode 1402 (Approach: Recursion + memoization)
// TC: O(n^2) | SC: O(n^2) - Recursion Stack Space + DP Array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
    {
        if (index == satisfaction.size())
            return 0;

        if (dp[index][time] != -1)
            return dp[index][time];

        int include = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1, dp);
        int exclude = 0 + solve(satisfaction, index + 1, time, dp);

        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(satisfaction, 0, 0, dp);
    }
};

int main()
{
    Solution solution;
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout << solution.maxSatisfaction(satisfaction) << endl; // Output: 14
    return 0;
}