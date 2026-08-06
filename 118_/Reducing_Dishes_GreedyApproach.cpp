// Reducing Dishes - Leetcode 1402 (Approach: Greedy Approach)
// TC: O(n log n) | SC: O(1) - Sorting + Constant Space

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());

        int max_satisfaction = 0;
        int current_sum = 0; // Cumulative sum of satisfaction values chosen

        // Process from most satisfying to least satisfying
        for (int index = satisfaction.size() - 1; index >= 0; index--)
        {
            current_sum += satisfaction[index];

            // If adding this dish makes the overall total decrease, stop
            if (current_sum <= 0)
                break;

            max_satisfaction += current_sum;
        }

        return max_satisfaction;
    }
};

int main()
{
    Solution solution;
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout << solution.maxSatisfaction(satisfaction) << endl; // Output: 14
    return 0;
}