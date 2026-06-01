// Circular Tour - GFG
#include <bits/stdc++.h>

using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

class Solution {
public:
    int tour(petrolPump p[], int n) {
        int start = 0, end = 1;
        int curr_petrol = p[start].petrol - p[start].distance;

        while (end != start || curr_petrol < 0) {
            while (curr_petrol < 0 && start != end) {
                curr_petrol -= p[start].petrol - p[start].distance;
                start = (start + 1) % n;

                if (start == 0) {
                    return -1; // No solution
                }
            }

            curr_petrol += p[end].petrol - p[end].distance;
            end = (end + 1) % n;
        }

        return start; // Starting point of the tour
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

