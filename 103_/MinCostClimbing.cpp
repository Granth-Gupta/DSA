// Minimum cost climbing stairs - LeetCode problem (746)
// TC: O(2^n) where n is the number of stairs
// SC: O(n) for recursion stack
// TLE may occur for large nStairs values as no memoization is used in this approach.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &cost, int n)
    {
        if (n == 0)
            return cost[0];
        if (n == 1)
            return cost[1];

        int ans = min(solve(cost, n - 1), solve(cost, n - 2)) + cost[n];
        return ans;
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        // Can be simplified more (see below commented code)
        int ans = min(solve(cost, n - 1), solve(cost, n - 2));
        return ans;

        // cost.push_back(0); // Top floor has 0 cost
        // return solve(cost, cost.size() - 1);
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