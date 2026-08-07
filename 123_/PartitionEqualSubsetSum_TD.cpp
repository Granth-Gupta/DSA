// Partion Equal Subset Sum - Leetcode 416 (Approach 2: Recursion + Memorization)
// TC: O(n^2) , SC: O(n^2)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool solve(vector<int> &nums, int index, int target, vector<vector<int>> &dp, int n)
    {
        if (target == 0)
            return true;
        if (index >= n || target < 0)
            return false;
        if (dp[index][target] != -1)
            return dp[index][target];

        bool incl = solve(nums, index + 1, target - nums[index], dp, n);
        bool excl = solve(nums, index + 1, target, dp, n);

        return dp[index][target] = incl or excl;
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
        {
            vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
            return solve(nums, 0, sum / 2, dp, n);
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 5, 11, 5};
    cout << s.canPartition(nums) << endl; // Output: 1 (true)
    return 0;
}