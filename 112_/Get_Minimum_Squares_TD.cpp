// Get Minimum Squares - GFG - Approach 2 (Recursion + Memoization)
// TC: O(n * sqrt(n)), SC: O(n) + O(n) for recursion stack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            int temp = i * i;
            ans = min(ans, 1 + solve(n - temp, dp));
        }

        dp[n] = ans;

        return dp[n];
    }

public:
    int minSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

int main()
{
    int n;
    cin >> n;
    Solution ob;
    cout << ob.minSquares(n) << endl;
    return 0;
}