// Smallest range from k Sorted Lists - CN - Approach 2 - Using k pointers {TC: O(n * k^2), SC: O(k)}

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> findSmallestRange(vector<vector<int>>& mat) {
    
    int k = mat.size();         
    int n = mat[0].size();   

    // Pointers for each of the k rows
    vector<int> ptr(k, 0);

    int minRange = INT_MAX;
    int start = -1, end = -1;

    while (true) {

        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        int minRow = -1;

        // Traverse all k rows to get current min and max
        for (int i = 0; i < k; i++) {

            // If any list is exhausted, stop the loop
            if (ptr[i] == n) {
                return {start, end};
            }

            // Track min value and its row index
            if (mat[i][ptr[i]] < minVal) {
                minVal = mat[i][ptr[i]];
                minRow = i;
            }

            // Track current max value
            if (mat[i][ptr[i]] > maxVal) {
                maxVal = mat[i][ptr[i]];
            }
        }

        // Update the result range if a 
        // smaller range is found
        if (maxVal - minVal < minRange) {
            minRange = maxVal - minVal;
            start = minVal;
            end = maxVal;
        }

        // Move the pointer of the 
        // row with minimum value
        ptr[minRow]++;
    }

    return {start, end};
}

int main() {

    vector<vector<int>>mat = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}
    };

    vector<int> res = findSmallestRange(mat);

    cout << res[0] << " " << res[1];

    return 0;
}