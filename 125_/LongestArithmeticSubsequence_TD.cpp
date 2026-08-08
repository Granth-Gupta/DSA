// Longest Arithmetic Subsequence - GFG - Approach: Top Down DP with Memoization (DP + Hashing - Top Down Approach) - TLE
// TC: O(n^2) SC: O(n^2)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &arr, int diff, int index, unordered_map<int, int> dp[])
    {
        if (index < 0)
            return 0;
        if (dp[index].count(diff))
            return dp[index][diff];

        int ans = 0;
        for (int i = index - 1; i >= 0; i--)
        {
            if (arr[index] - arr[i] == diff)
                ans = max(ans, 1 + solve(arr, diff, i, dp));
        }
        return dp[index][diff] = ans;
    }

public:
    int lengthOfLongestAP(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 2)
            return n;

        // Hashmap to store the results of subproblems for each index
        unordered_map<int, int> dp[n + 1];

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 1; j < n; j++)
            {
                ans = max(ans, 2 + solve(arr, arr[j] - arr[i], i, dp));
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