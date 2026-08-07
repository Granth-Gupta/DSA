// Longest Arithmetic Subsequence - GFG - Approach: Brute Force - TLE
// TC: O(n^3) SC: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &arr, int diff, int index)
    {
        if (index < 0)
            return 0;

        int ans = 0;
        for (int i = index - 1; i >= 0; i--)
        {
            if (arr[index] - arr[i] == diff)
                ans = max(ans, 1 + solve(arr, diff, i));
        }
        return ans;
    }

public:
    int lengthOfLongestAP(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 2)
            return n;

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 1; j < n; j++)
            {
                ans = max(ans, 2 + solve(arr, arr[j] - arr[i], i));
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 7, 10, 13, 14, 19};
    cout << sol.lengthOfLongestAP(arr) << endl; // Output: 4
    return 0;
}