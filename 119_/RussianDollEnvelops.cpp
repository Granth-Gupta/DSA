// Russian Doll Envelops - Leetcode 354 (Approach: Longest Increasing Subsequence)
// TC: O(nlogn), SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        if (n == 0)
            return 0;

        // Sort the envelopes by width in ascending order and by height in descending order for equal widths
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });

        // Extract the heights of the sorted envelopes
        vector<int> heights;
        for (const auto &envelope : envelopes)
        {
            heights.push_back(envelope[1]);
        }

        // Find the length of the longest increasing subsequence of heights
        vector<int> dp;
        for (int height : heights)
        {
            auto it = lower_bound(dp.begin(), dp.end(), height);
            if (it == dp.end())
            {
                dp.push_back(height);
            }
            else
            {
                *it = height;
            }
        }

        return dp.size();
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout << "Maximum number of envelopes: " << sol.maxEnvelopes(envelopes) << endl;
    return 0;
}