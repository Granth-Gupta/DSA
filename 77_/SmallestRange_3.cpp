// Smallest range from k Sorted Lists - CN - Approach 3 - Using Min Heap {TC: O(n * k * log k), SC: O(k)}

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Compare {
public:
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.first > b.first;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> minHeap;

    int maxVal = INT_MIN;
    int minRange = INT_MAX;

    // Step 1: Initialize the min heap with the first element of each list
    for (int i = 0; i < k; i++) {
        minHeap.push({a[i][0], {i, 0}});
        maxVal = max(maxVal, a[i][0]);
    }

    // Step 2: Extract the minimum element and push the next element from the same list

    while (true) {
        auto minElement = minHeap.top();
        minHeap.pop();

        int minVal = minElement.first;
        int row = minElement.second.first;
        int col = minElement.second.second;

        // Update the range if it's smaller than the current minimum range
        if (maxVal - minVal < minRange) {
            minRange = maxVal - minVal;
        }

        // If we have reached the end of one of the lists, we cannot find a smaller range
        if (col + 1 == n) {
            break;
        }

        // Push the next element from the same list into the heap
        int nextVal = a[row][col + 1];
        minHeap.push({nextVal, {row, col + 1}});
        maxVal = max(maxVal, nextVal);
    }

    return minRange;
}

int main() {
    vector<vector<int>> a = {{4, 7, 9, 12, 15}, {0, 8, 10, 14, 20}, {6, 12, 16, 30, 50}};
    int k = a.size();
    int n = a[0].size();
    
    cout << "Smallest Range: " << kSorted(a, k, n) << endl; // Output: 2
    return 0;
}