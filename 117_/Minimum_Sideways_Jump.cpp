// Minimum Sideways Jump - Leetcode 1824 (Approach: Simple recursion) - TLE
// TC: O(3^n) where n is the length of the obstacles array
// SC: O(n) for recursion stack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &obstacles, int currlane, int currpos)
    {
        int n = obstacles.size() - 1;
        if (currpos == n)
            return 0;

        if (obstacles[currpos + 1] != currlane)
            return solve(obstacles, currlane, currpos + 1);
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (currlane != i && obstacles[currpos] != i)
                {
                    ans = min(ans, 1 + solve(obstacles, i, currpos));
                }
            }
            return ans;
        }
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {
        return solve(obstacles, 2, 0);
    }
};

int main()
{
    Solution sol;
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << sol.minSideJumps(obstacles) << endl; // Output: 2
    return 0;
}