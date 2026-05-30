// First Negative Integer In Every Window Of Size K
// https://www.naukri.com/code360/problems/first-negative-integer-in-every-window-of-size-k_1164406?leftPanelTabValue=PROBLEM

// Approach 2
// TC: O(n) and SC: O(1)

#include <iostream>
#include <vector>

using namespace std;

vector<int> firstNegInt(vector<int>& arr, int k) {
    int fstNegIdx = 0;
    vector<int> res;
    int n = arr.size(); 

    for (int i = k - 1; i < n; i++) {
        
        // Skip out of window and positive elements
        while ((fstNegIdx < i) && (fstNegIdx <= i - k || arr[fstNegIdx] >= 0)) {
            fstNegIdx++;
        }

        // Check if a negative element is found, 
        // otherwise use 0
        if (fstNegIdx < n && arr[fstNegIdx] < 0) {
            res.push_back(arr[fstNegIdx]);
        }
        else {
            res.push_back(0);
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