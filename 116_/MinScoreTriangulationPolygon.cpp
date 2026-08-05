// Minumum Score triangulation of polygon - LeetCode 1039 (Approach-1: Recursion) -> TLE
// TC: O(2^n) SC: O(n) + O(n^2) (Recursion + Recursion Stack)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &v, int i, int j)
    {
        if (i + 1 == j)
            return 0;

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, v[i] * v[j] * v[k] + solve(v, i, k) + solve(v, k, j));
        }
        return ans;
    }

public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        return solve(values, 0, n - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> values = {1, 2, 3, 4};
    cout << sol.minScoreTriangulation(values) << endl;

    return 0;
}