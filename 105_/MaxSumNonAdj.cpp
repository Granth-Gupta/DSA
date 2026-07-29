// Maximum sum of non-adjacent - CN
// TC: O(2^n) SC: O(n)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int sum, int index)
{
    if (index >= nums.size())
        return sum;

    int maxi = INT_MIN;
    int in = solve(nums, sum + nums[index], index + 2);
    int ex = solve(nums, sum, index + 1);
    maxi = max(in, ex);

    return maxi;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int ans = solve(nums, 0, 0);
    return ans;
}