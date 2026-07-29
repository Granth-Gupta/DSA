// House Robber II - CN (Approach 1: DP with Bottom Up and Space Optimization)
// TC: O(n)  SC: O(1)

#include <bits/stdc++.h>
using namespace std;

long long int solve(vector<int> &nums)
{
    int n = nums.size();

    long long int prev2 = 0;
    long long int prev1 = nums[0];

    for (long long int i = 1; i < n; i++)
    {
        long long int incl = prev2 + nums[i];
        long long int excl = prev1;

        long long int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();

    if (n == 1)
        return valueInHouse[0];

    vector<int> first, last;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            first.push_back(valueInHouse[i]);
        if (i != 0)
            last.push_back(valueInHouse[i]);
    }

    return max(solve(first), solve(last));
}

int main()
{
    vector<int> valueInHouse = {2, 3, 2};
    cout << houseRobber(valueInHouse) << endl; // Output: 3

    return 0;
}