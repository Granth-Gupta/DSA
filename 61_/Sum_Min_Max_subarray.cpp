// Sum of minimum and maximum elements of all subarrays of size k (GFG)
// Using Deque to maintain the indices of the elements in the current window and calculating the sum of minimum and maximum for each subarray of size k in O(n) time complexity.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
    deque<int> maxi, mini;
    long long ans = 0;

    for(int i = 0; i < n; i++) {

        // Remove indices outside current window
        while(!maxi.empty() && maxi.front() <= i - k) {
            maxi.pop_front();
        }

        while(!mini.empty() && mini.front() <= i - k) {
            mini.pop_front();
        }

        // Maintain decreasing deque for maximum
        while(!maxi.empty() && nums[maxi.back()] <= nums[i]) {
            maxi.pop_back();
        }

        // Maintain increasing deque for minimum
        while(!mini.empty() && nums[mini.back()] >= nums[i]) {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        // Add max + min when first window is completed
        if(i >= k - 1) {
            ans += nums[maxi.front()] + nums[mini.front()];
        }
    }

    return ans;
}
};

int main() {
    vector<int> arr = {2, 4, 7, 3, 8, 1};
    int k = 4;

    Solution sol;
    long long result = sol.sumOfMaxAndMin(arr, arr.size(), k);
    cout << "Sum of minimum and maximum elements of all subarrays of size " << k << " is: " << result << endl;

    return 0;
}
