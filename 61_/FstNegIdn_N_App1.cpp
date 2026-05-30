// First Negative Integer In Every Window Of Size K
// https://www.naukri.com/code360/problems/first-negative-integer-in-every-window-of-size-k_1164406?leftPanelTabValue=PROBLEM

// Approach 1
// TC: O(n) and SC: O(2)
// Using Deque

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> firstNegInt(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> res;
    int n = arr.size(); 

    for (int i = 0; i < n; i++) {
        // Remove out of window elements
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove positive elements from the back
        while (!dq.empty() && arr[dq.back()] >= 0) {
            dq.pop_back();
        }

        // Add current element index to the back
        dq.push_back(i);

        // Check if a negative element is found, 
        // otherwise use 0
        if (i >= k - 1) {
            if (!dq.empty() && arr[dq.front()] < 0) {
                res.push_back(arr[dq.front()]);
            }
            else {
                res.push_back(0);
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};  
    int k = 3;
    vector<int> res = firstNegInt(arr, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}

