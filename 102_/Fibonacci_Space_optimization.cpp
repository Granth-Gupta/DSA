// Space Optimization of Fibonacci using Dynamic Programming Bottom-Up Approach (Tabulation)
// TC: O(n)
// SC: O(1)

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int prev1 = 1;
    int prev2 = 0;

    if (n == 0)
    {
        cout << prev2;
        return 0;
    }

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;

        // Shifting the values for the next iteration
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1;

    return 0;
}