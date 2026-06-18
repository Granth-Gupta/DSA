// Smallest range from k Sorted Lists - CN - Approach 1 - Using Brute Force {TC: O(n^2 * k^2), SC: O(1)}

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int kSorted(vector<vector<int>> &a, int k, int n) {
    int minRange = INT_MAX;

    // Step 1: Pick every single element as a potential minVal -> O(n * k)
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            int minVal = a[i][j];
            int maxVal = INT_MIN;
            bool isValid = true;

            // Step 2: For this minVal, find the required maxVal by scanning all k lists -> O(k * n)
            for (int l = 0; l < k; l++) {
                int firstValidElement = -1;
                
                // Linear scan inside the list to find the first element >= minVal
                for (int m = 0; m < n; m++) {
                    if (a[l][m] >= minVal) {
                        firstValidElement = a[l][m];
                        break;
                    }
                }

                // If a list doesn't have any element >= minVal, this minVal cannot form a valid range
                if (firstValidElement == -1) {
                    isValid = false;
                    break;
                }

                // The overall maxVal for this range will be the maximum of these first valid elements
                maxVal = max(maxVal, firstValidElement);
            }

            // If valid, calculate the range
            if (isValid) {
                minRange = min(minRange, maxVal - minVal);
            }
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