// Longest Increasing Subsequence - Coding Ninjas
// TC: O(n log n), SC: O(n)

#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> tails;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(tails.begin(), tails.end(), arr[i]);
        if (it == tails.end())
            tails.push_back(arr[i]);
        else
            *it = arr[i];
    }

    return tails.size();
}

int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestIncreasingSubsequence(arr, n) << endl; // Output: 4
    return 0;
}
