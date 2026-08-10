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

        for (int i = 0; i < arr.size(); i++)
        {
            int temp = arr[i] - diff;
            int tempAns = 0;

            if (dp.count(temp))
                tempAns = dp[temp];

            dp[arr[i]] = 1 + tempAns;
            ans = max(ans, dp[arr[i]]);
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