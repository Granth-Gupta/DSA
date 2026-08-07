// Dice Throw Problem - GFG (Approach: Simple Recursion) - TLE
// TC: O(m^n) SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int faces, int dice, int target)
    {
        if (target < 0 || (target != 0 && dice == 0) || (target == 0 && dice != 0))
            return 0;
        if (target == 0 && dice == 0)
            return 1;

        int ans = 0;
        for (int i = 1; i <= faces; i++)
        {
            ans = ans + solve(faces, dice - 1, target - i);
        }
        return ans;
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