// Maximum sum of non-adjacent - CN (Approach 1: Simple Recursion)
// TC: O(2^n) SC: O(n)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int n)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return nums[0];

    int in = solve(nums, n - 2) + nums[n];
    int ex = solve(nums, n - 1);

    return max(in, ex);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int ans = solve(nums, n - 1);
    return ans;
}

int main()
{
    vector<int> nums = {2, 1, 4, 9};
    cout << maximumNonAdjacentSum(nums) << endl;

    return 0;
}