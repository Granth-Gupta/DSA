// Reducing Dishes - Leetcode 1402 (Approach: Bottom-Up DP + Space Optimization)
// TC: O(n^2) | SC: O(n) - DP Array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &satisfaction)
    {
        int n = satisfaction.size();

        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                int include = satisfaction[index] * (time + 1) + next[time + 1];
                int exclude = 0 + next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }

        return next[0];
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());

        return solve(satisfaction);
    }
};

int main()
{
    Solution solution;
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout << solution.maxSatisfaction(satisfaction) << endl; // Output: 14
    return 0;
}