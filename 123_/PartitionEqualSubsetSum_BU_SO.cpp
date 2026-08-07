// Partion Equal Subset Sum - Leetcode 416 (Approach 4: Bottom Up DP with Space Optimization)
// TC: O(sum/2 * n) , SC: O(sum/2)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool solve(vector<int> &nums, int t, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int target = 1; target <= t; target++)
            {
                bool incl = false;
                if (target - nums[index] >= 0)
                    incl = dp[index + 1][target - nums[index]];

                bool excl = dp[index + 1][target];

                dp[index][target] = incl or excl;
            }
        }
        return dp[0][t];
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        if (sum & 1)
            return false;
        else
            return solve(nums, sum / 2, n);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 5, 11, 5};
    cout << s.canPartition(nums) << endl; // Output: 1 (true)
    return 0;
}