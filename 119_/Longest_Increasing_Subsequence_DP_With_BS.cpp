// Longest Increasing Subsequence - Leetcode 300 (Approach 5: DP with Binary Search) - Best
// TC: O(nlogn), SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &nums, int n)
    {
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > ans.back())
                ans.push_back(nums[i]);
            else
            {
                // index of just badaa number in ans
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                // Here lower_bound uses binary search to find the index of the first element in ans that is not less than nums[i]

                ans[index] = nums[i];
            }
        }
        return ans.size();
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