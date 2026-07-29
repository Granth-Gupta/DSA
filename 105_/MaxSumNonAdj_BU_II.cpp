// Maximum Sum of Non-Adjacent Elements (Bottom-Up Approach)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, 0);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int incl = dp[i - 2] + nums[i];
        int excl = dp[i - 1];
        dp[i] = max(incl, excl);
    }

    return dp[n - 1];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    return solve(nums);
}

int main()
{
    vector<int> nums = {2, 1, 4, 9};
    cout << maximumNonAdjacentSum(nums) << endl;

    return 0;
}