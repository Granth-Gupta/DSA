// Longest Increasing Subsequence - Leetcode 300 (Approach 4: Bottom-Up DP with Space Optimization)
// TC: O(n^2), SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &nums, int n)
    {
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int incl = 0;
                if (prev == -1 || nums[curr] > nums[prev])
                    incl = 1 + nextRow[curr + 1];

                int excl = nextRow[prev + 1];

                currRow[prev + 1] = max(incl, excl);
            }
            nextRow = currRow;
        }
        return nextRow[0];
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