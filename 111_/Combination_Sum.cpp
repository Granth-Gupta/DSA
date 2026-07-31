// Combination Sum IV - CN (Approach1: Recursion)
// TC: O(n^target) SC: O(target) + O(target) for recursion stack
// SC: O(target) + O(target) for recursion stack

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &num, int tar)
{
    if (tar == 0)
        return 1;
    if (tar < 0)
        return 0;

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solve(num, tar - num[i]);
    }
    return ans;
}

int findWays(vector<int> &num, int tar)
{
    return solve(num, tar);
}

int main()
{
    vector<int> num = {1, 2, 3};
    int tar = 4;

    cout << findWays(num, tar) << endl;

    return 0;
}
