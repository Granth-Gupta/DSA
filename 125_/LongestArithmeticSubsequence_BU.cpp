// Longest Arithmetic Subsequence - GFG - Approach: Bottom Up DP with Hashing (DP + Hashing - Bottom Up Approach) - AC
// TC: O(n^2) SC: O(n^2)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestAP(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 2)
            return n;

        unordered_map<int, int> dp[n + 1];
        int ans = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = arr[i] - arr[j];
                int cnt = 1;

                // Check if count already present
                if (dp[j].count(diff))
                    cnt = dp[j][diff];

                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
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