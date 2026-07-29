// Minimum elements - CN (Bottom Up Approach with Tabulation)
// TC = O(n*x) where n is the size of the num array and x is the target sum
// SC = O(x) for the dp array

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &num, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - num[j]] + 1);
            }
        }
    }

    if (dp[x] == INT_MAX)
        return -1;

    return dp[x];
}

int main()
{
    vector<int> num = {1, 2, 3};
    int x;
    cout << "Target sum: ";
    cin >> x;

    int ans = solve(num, x);
    cout << "Minimum elements required: " << ans << endl;

    return 0;
}