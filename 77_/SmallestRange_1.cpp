// Smallest range from k Sorted Lists - CN - Approach 1 - Using Brute Force {TC: O(n^k) SC: O(k)}

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// Helper function to find all combinations using recursion
void findSmallestRange(vector<vector<int>> &a, int k, int n, int listIdx, vector<int> &currentCombination, int &minRange) {
    // Base Case: If we have picked one element from all k lists
    if (listIdx == k) {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        
        for (int val : currentCombination) {
            minVal = min(minVal, val);
            maxVal = max(maxVal, val);
        }
        
        minRange = min(minRange, maxVal - minVal);
        return;
    }

    // Try picking every element from the current list
    for (int i = 0; i < n; i++) {
        currentCombination.push_back(a[listIdx][i]);
        findSmallestRange(a, k, n, listIdx + 1, currentCombination, minRange);
        currentCombination.pop_back(); // Backtrack
    }
}

int kSorted(vector<vector<int>> &a, int k, int n) {
    int minRange = INT_MAX;
    vector<int> currentCombination;
    findSmallestRange(a, k, n, 0, currentCombination, minRange);
    return minRange;
}

int main() {
    vector<vector<int>> a = {{4, 7, 9, 12, 15}, {0, 8, 10, 14, 20}, {6, 12, 16, 30, 50}};
    int k = a.size();
    int n = a[0].size();
    
    // Correct Output for this test case: 2 (from elements [7, 8, 6] -> range is 8 - 6 = 2)
    cout << "Smallest Range: " << kSorted(a, k, n) << endl; 
    return 0;
}