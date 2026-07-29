// Maximum Sum of Non-Adjacent Elements (Bottom-Up Space Optimized Approach)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        int incl = prev2 + nums[i];
        int excl = prev1;
        int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
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