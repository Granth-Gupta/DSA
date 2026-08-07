// Pizza with 3n slices - Leetcode 1388 (Approach 1: Simple Recursion) - TLE
// TC: O(2^n) SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &slices, int endIndex, int index, int n)
    {
        if (n == 0 || index > endIndex)
            return 0;
        int incl = slices[index] + solve(slices, endIndex, index + 2, n - 1);
        int excl = solve(slices, endIndex, index + 1, n);

        return max(incl, excl);
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        int k = slices.size();
        int FirstTake = solve(slices, k - 2, 0, k / 3);
        int FirstNotTake = solve(slices, k - 1, 1, k / 3);

        return max(FirstTake, FirstNotTake);
    }
};

int main()
{
    Solution s;
    vector<int> slices = {1, 2, 3, 4, 5, 6};
    cout << s.maxSizeSlices(slices) << endl;
    return 0;
}