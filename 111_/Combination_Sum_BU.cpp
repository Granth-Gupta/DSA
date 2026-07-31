// Combination Sum IV - Bottom Up Approach
// TC: O(n*target)
// SC: O(target)

// Space optimized version of the above code is not possible.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= tar; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0)
                dp[i] += dp[i - num[j]];
        }
    }

    return dp[tar];
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