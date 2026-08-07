// Partion Equal Subset Sum - Leetcode 416 (Approach 1: Recursion) - TLE
// TC: O(2^n), SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool solve(vector<int> &nums, int index, int target)
    {
        if (index >= nums.size() || target < 0)
            return false;
        if (target == 0)
            return true;

        bool incl = solve(nums, index + 1, target - nums[index]);
        bool excl = solve(nums, index + 1, target);

        return incl or excl;
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        if (sum & 1)
            return false;
        else
            return solve(nums, 0, sum / 2);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 5, 11, 5};
    cout << s.canPartition(nums) << endl; // Output: 1 (true)
    return 0;
}