// Longest Increasing Subsequence - Leetcode 300 (Approach 2: Recursion + Memoization) - Accepted
// TC: O(n^2), SC: O(n^2) + O(n) - Recursion stack space

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &nums, int n, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == n)
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        // if, no + 1 then error as prev may be equal to -1
        // But since prev range is -1 to n-1 , Thus now it is 0 to n

        int incl = 0;
        if (prev == -1 || nums[curr] > nums[prev])
            incl = 1 + solve(nums, n, curr + 1, curr, dp);

        int excl = solve(nums, n, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(incl, excl);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(nums, n, 0, -1, dp);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}