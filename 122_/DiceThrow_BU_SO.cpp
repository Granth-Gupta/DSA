// Dice Throw Problem - GFG (Approach: Bottom-Up Dynamic Programming with Space Optimization)
// TC: O(n * x * m) SC: O(x)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int m, int n, int x)
    {
        vector<int> prev(x + 1, 0);
        vector<int> curr(x + 1, 0);

        prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= x; j++)
            {
                int ans = 0;
                for (int k = 1; k <= m && j - k >= 0; k++)
                {
                    ans += prev[j - k];
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        return prev[x];
    }

public:
    int noOfWays(int m, int n, int x)
    {
        return solve(m, n, x);
    }
};

int main()
{
    int m = 6, n = 3, x = 12;
    Solution obj;
    cout << obj.noOfWays(m, n, x) << endl;
    return 0;
}