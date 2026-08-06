// Minimum Sideways Jump - Leetcode 1824 (Approach: Bottom Up DP + space optimization)
// TC: O(n) where n is the length of the obstacles array
// SC: O(4) ~ O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &obstacles)
    {
        int n = obstacles.size() - 1;

        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);

        for (int i = 0; i <= 3; i++)
            next[i] = 0;

        for (int currpos = n - 1; currpos >= 0; currpos--)
        {
            for (int currlane = 1; currlane <= 3; currlane++)
            {
                if (obstacles[currpos + 1] != currlane)
                    curr[currlane] = next[currlane];
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (currlane != i && obstacles[currpos] != i)
                            ans = min(ans, 1 + next[i]);
                    }
                    curr[currlane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(1 + next[1], 1 + next[3]));
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {
        return solve(obstacles);
    }
};

int main()
{
    Solution sol;
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << sol.minSideJumps(obstacles) << endl; // Output: 2
    return 0;
}