// Longest AP - Leetcode 1218 (Approach: Bottom Up DP)
// TC: O(n), SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int diff)
    {
        unordered_map<int, int> dp;
        int ans = 0;

        for (int num : arr)
        {
            // If num - diff exists, dp[num - diff] returns its value.
            // If it doesn't exist, accessing it or using .find() defaults to 0.
            dp[num] = dp[num - diff] + 1;
            ans = max(ans, dp[num]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int difference = -2;
    cout << sol.longestSubsequence(arr, difference) << endl; // Output: 4
    return 0;
}