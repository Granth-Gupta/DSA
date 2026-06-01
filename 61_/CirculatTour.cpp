// Circular Tour - GFG
// Using the concept of two pointers to find the starting point of the tour in O(n) time complexity.

#include <bits/stdc++.h>

using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

class Solution {
public:
    int tour(petrolPump p[], int n) {
        int deficit = 0;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            balance += p[i].petrol - p[i].distance;

            if (balance < 0) {
                deficit += balance;
                balance = 0;
                start = i + 1;
            }
        }

        return (balance + deficit >= 0) ? start : -1;
    }
};

int main() {
    int n = 4;
    petrolPump p[] = {{6, 4}, {3, 6}, {7, 3}, {4, 5}};

    Solution sol;
    int startPoint = sol.tour(p, n);
    if (startPoint != -1) {
        cout << "Starting point of the tour is: " << startPoint << endl;
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}

