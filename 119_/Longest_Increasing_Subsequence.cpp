// Longest Increasing Subsequence - Leetcode 300 (Approach 1: Simple recursion) - TLE
// TC: O(2^n), SC: O(n) - Recursion stack space

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &nums, int n, int curr, int prev)
    {
        if (curr == n)
            return 0;

        int incl = 0;
        if (prev == -1 || nums[curr] > nums[prev])
            incl = 1 + solve(nums, n, curr + 1, curr);

        int excl = solve(nums, n, curr + 1, prev);

        return max(incl, excl);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return solve(nums, n, 0, -1);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}