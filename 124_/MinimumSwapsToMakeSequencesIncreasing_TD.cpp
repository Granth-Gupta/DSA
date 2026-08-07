// Minimum Swaps To Make Sequences Increasing - Leetcode 801 - Approach Recursion with Memoization
// TC: O(n) SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &nums1, vector<int> &nums2, int index, int swapped, vector<vector<int>> &dp)
    {
        if (index == nums1.size())
            return 0;
        if (dp[index][swapped] != -1)
            return dp[index][swapped];

        int ans = INT_MAX;

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (swapped)
            swap(prev1, prev2);

        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index + 1, 0, dp);

        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1, dp));

        return dp[index][swapped] = ans;
    }

public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, -1));

        int swapped = 0;
        return solve(nums1, nums2, 1, swapped, dp);
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 3, 5, 4};
    vector<int> nums2 = {1, 2, 3, 7};
    cout << sol.minSwap(nums1, nums2) << endl; // Output: 1
    return 0;
}