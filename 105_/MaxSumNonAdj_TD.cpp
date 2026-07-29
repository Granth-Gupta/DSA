// Maximum sum of non-adjacent - CN (Approach: Top-Down Dynamic Programming)
// TC: O(n) SC: O(n) + O(n) (Recursion Stack Space + DP Array)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int n, vector<int> &dq)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return nums[0];

    if (dq[n] != -1)
        return dq[n];

    int in = solve(nums, n - 2, dq) + nums[n];
    int ex = solve(nums, n - 1, dq);

    dq[n] = max(in, ex);

    return dq[n];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dq(n, -1);
    int ans = solve(nums, n - 1, dq);
    return ans;
}

int main()
{
    vector<int> nums = {2, 1, 4, 9};
    cout << maximumNonAdjacentSum(nums) << endl;

    return 0;
}