// Partion Equal Subset Sum - Leetcode 416 (Approach 4: Bottom Up DP with Space Optimization)
// TC: O(sum/2 * n) , SC: O(sum/2)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool solve(vector<int> &nums, int t, int n)
    {
        vector<int> next(t + 1, 0);
        vector<int> curr(t + 1, 0);

        next[0] = 1;
        curr[0] = 1;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int target = 1; target <= t; target++)
            {
                bool incl = false;
                if (target - nums[index] >= 0)
                    incl = next[target - nums[index]];

                bool excl = next[target];

                curr[target] = incl or excl;
            }
            next = curr;
        }
        return next[t];
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