// Minimum cost climbing stairs - LeetCode problem (746) - using Bottom up DP approach
// TC: O(n) where n is the number of stairs
// SC: O(n) for recursion stack + O(n) for dp array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &cost, int n)
    {
        vector<int> dp(n + 1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }

        return min(dp[n - 1], dp[n - 2]);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        return solve(cost, n);
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