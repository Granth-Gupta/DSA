// Smallest range from k Sorted Lists - CN - Approach 3 - Using Min Heap {TC: O(n * k * log k), SC: O(k)}

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    int row;
    int col;

    Node(int v, int r, int c) : val(v), row(r), col(c) {}
};

class Compare {
public:
    bool operator()( Node &a, Node &b) {
        return a.val > b.val; 
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<Node, vector<Node>, Compare> minHeap;
    int maxVal = INT_MIN;
    int minRange = INT_MAX;

    // Step 1: Initialize the min heap with the first element of each list
    for (int i = 0; i < k; i++) {
        minHeap.push(Node(a[i][0], i, 0));
        maxVal = max(maxVal, a[i][0]);
    }

    // Step 2: Extract the minimum element and add the next element from the same list
    while (!minHeap.empty()) {
        Node minNode = minHeap.top();
        minHeap.pop();

        // Update the range if the current range is smaller
        int currentRange = maxVal - minNode.val;
        if (currentRange < minRange) {
            minRange = currentRange;
        }

        // If there is a next element in the same list, add it to the heap
        if (minNode.col + 1 < n) {
            int nextVal = a[minNode.row][minNode.col + 1];
            minHeap.push(Node(nextVal, minNode.row, minNode.col + 1));
            maxVal = max(maxVal, nextVal);
        } else {
            // If we have exhausted one of the lists, we can stop
            break;
        }
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