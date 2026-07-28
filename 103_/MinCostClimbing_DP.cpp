// Minimum cost climbing stairs - LeetCode problem (746) - using DP approach (Top down approach with memoization)
// TC: O(n) where n is the number of stairs
// SC: O(n) for recursion stack + O(n) for dp array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &cost, int n, vector<int> &dp)
    {
        if (n == 0)
            return cost[0];
        if (n == 1)
            return cost[1];

        if (dp[n] != -1)
            return dp[n];

        dp[n] = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp)) + cost[n];
        return dp[n];
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> cost = {10, 15, 20};
    int ans = s.minCostClimbingStairs(cost);
    cout << ans << endl;

    return 0;
}