// Reducing Dishes - Leetcode 1402 (Approach: Recursion)
// TC: O(2^n) | SC: O(n) - Recursion Stack Space

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &satisfaction, int index, int time)
    {
        if (index == satisfaction.size())
            return 0;

        int include = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1);
        int exclude = 0 + solve(satisfaction, index + 1, time);

        return max(include, exclude);
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0, 0);
    }
};

int main()
{
    Solution solution;
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout << solution.maxSatisfaction(satisfaction) << endl; // Output: 14
    return 0;
}