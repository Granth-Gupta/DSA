// Pizza with 3n slices - Leetcode 1388 (Approach 4: Tabulation + Space Optimization) - Bottom Up
// TC: O(n^2) SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &slices)
    {
        int k = slices.size();

        vector<int> prev1(k + 2, 0);
        vector<int> curr1(k + 2, 0);
        vector<int> next1(k + 2, 0);

        vector<int> prev2(k + 2, 0);
        vector<int> curr2(k + 2, 0);
        vector<int> next2(k + 2, 0);

        for (int index = k - 1; index >= 1; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int incl = slices[index] + next1[n - 1];
                int excl = curr1[n];

                prev1[n] = max(incl, excl);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int FirstNotTake = curr1[k / 3];

        for (int index = k - 2; index >= 0; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int incl = slices[index] + next2[n - 1];
                int excl = curr2[n];

                prev2[n] = max(incl, excl);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int FirstTake = curr2[k / 3];

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