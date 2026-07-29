// Maximum sum of non-adjacent - CN (Approach: Bottom-Up Dynamic Programming)
// TC: O(n) SC: O(n)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 2, 0); // Extra size to handle i + 1 and i + 2 cleanly

    for (int i = n - 1; i >= 0; i--)
    {
        int incl = dp[i + 2] + nums[i];
        int excl = dp[i + 1];
        dp[i] = max(incl, excl);
    }

    return dp[0];
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