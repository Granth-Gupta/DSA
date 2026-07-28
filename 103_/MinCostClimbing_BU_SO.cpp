// Minimum cost climbing stairs - using Bottom up DP approach with space optimization
// TC: O(n) where n is the number of stairs
// SC: O(1) for recursion stack + O(1) for dp array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &cost, int n)
    {
        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++)
        {
            int curr = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
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