// Longest Increasing Subsequence - Leetcode 300 (Approach 3: Bottom-Up DP) - Accepted
// TC: O(n^2), SC: O(n^2)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &nums, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int incl = 0;
                if (prev == -1 || nums[curr] > nums[prev])
                    incl = 1 + dp[curr + 1][curr + 1];

                int excl = dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(incl, excl);
            }
        }

        return dp[0][0];
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return solve(nums, n);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}