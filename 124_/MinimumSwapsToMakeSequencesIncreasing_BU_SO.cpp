// Minimum Swaps To Make Sequences Increasing - Leetcode 801 - Approach Bottom Up DP with Space Optimization
// TC: O(n) SC: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index > 0; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = INT_MAX;

                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if (swapped)
                    swap(prev1, prev2);

                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index + 1][0];

                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + dp[index + 1][1]);

                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }

public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int swapped = 0;
        return solve(nums1, nums2);
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