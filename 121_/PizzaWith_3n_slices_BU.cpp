// Pizza with 3n slices - Leetcode 1388 (Approach 3: Tabulation) - Bottom Up
// TC: O(n^2) SC: O(n^2)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &slices)
    {
        int k = slices.size();

        vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

        for (int index = k - 1; index >= 1; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int incl = slices[index] + dp1[index + 2][n - 1];
                int excl = dp1[index + 1][n];

                dp1[index][n] = max(incl, excl);
            }
        }
        int FirstNotTake = dp1[1][k / 3];

        for (int index = k - 2; index >= 0; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int incl = slices[index] + dp2[index + 2][n - 1];
                int excl = dp2[index + 1][n];

                dp2[index][n] = max(incl, excl);
            }
        }
        int FirstTake = dp2[0][k / 3];

        return max(FirstTake, FirstNotTake);
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        return solve(slices);
    }
};

int main()
{
    Solution s;
    vector<int> slices = {1, 2, 3, 4, 5, 6};
    cout << s.maxSizeSlices(slices) << endl;
    return 0;
}