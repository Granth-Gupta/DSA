// Pizza with 3n slices - Leetcode 1388 (Approach 2: Recursion + Memoization)
// TC: O(n^2) SC: O(n^2)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &slices, int endIndex, int index, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || index > endIndex)
            return 0;

        if (dp[index][n - 1] != -1)
            return dp[index][n - 1];

        int incl = slices[index] + solve(slices, endIndex, index + 2, n - 1, dp);
        int excl = solve(slices, endIndex, index + 1, n, dp);

        return dp[index][n - 1] = max(incl, excl);
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        int k = slices.size();

        vector<vector<int>> dp1(k, vector<int>(k / 3, -1));
        int FirstTake = solve(slices, k - 2, 0, k / 3, dp1);

        vector<vector<int>> dp2(k, vector<int>(k / 3, -1));
        int FirstNotTake = solve(slices, k - 1, 1, k / 3, dp2);

        return max(FirstTake, FirstNotTake);
    }
};

int main()
{
    Solution s;
    vector<int> slices = {1, 2, 3, 4, 5, 6};
    cout << s.maxSizeSlices(slices) << endl;
    return 0;
}