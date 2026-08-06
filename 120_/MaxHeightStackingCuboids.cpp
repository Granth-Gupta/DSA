// Maximum height of stacked cuboids - Leetcode 1691 (Approach : Bottom up DP + space optimization)
// TC: O(n^2) SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool checkBox(vector<int> &base, vector<int> &newBox)
    {
        if (base[0] >= newBox[0] && base[1] >= newBox[1] && base[2] >= newBox[2])
            return true;
        return false;
    }
    int solve(vector<vector<int>> &cuboids, int n)
    {
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int incl = 0;
                if (prev == -1 || checkBox(cuboids[curr], cuboids[prev]))
                    incl = cuboids[curr][2] + nextRow[curr + 1];

                int excl = nextRow[prev + 1];

                currRow[prev + 1] = max(incl, excl);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        // Step 1: Sorting all rows such that Height (index 2) is max
        for (auto &a : cuboids)
            sort(a.begin(), a.end());

        // Step 2: Sort by column so that we can apply LIS later
        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids, cuboids.size());
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> cuboids = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
    cout << sol.maxHeight(cuboids) << endl; // Output: 190
    return 0;
}