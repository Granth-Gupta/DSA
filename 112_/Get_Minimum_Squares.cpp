// Get Minimum Squares - GFG - Approach 1 (Recursion)
// TC: O(n * sqrt(n)), SC: O(n) + O(n) for recursion stack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n)
    {
        if (n == 0)
            return 0;

        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            int temp = i * i;
            ans = min(ans, 1 + solve(n - temp));
        }
        return ans;
    }
    int MinSquares(int n)
    {
        return solve(n);
    }
};

int main()
{
    int n;
    cin >> n;
    Solution ob;
    cout << ob.MinSquares(n) << endl;
    return 0;
}