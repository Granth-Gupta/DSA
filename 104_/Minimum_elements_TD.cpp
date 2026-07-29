// Minimum elements - CN (Top Down Approach with Memoization)
// TC = O(n*x) where n is the size of the num array and x is the target sum
// SC = O(x) for the memoization array and O(x) for the recursion stack space

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &num, int x, vector<int> &dq)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    if (dq[x] != -1)
        return dq[x];

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solve(num, x - num[i], dq);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }

    dq[x] = mini;

    return mini;
}

int minimumElements(vector<int> &num, int x)
{
    vector<int> dq(x + 1, -1);
    int ans = solve(num, x, dq);

    if (ans == INT_MAX)
        return -1;
    return ans;
}

int main()
{
    vector<int> num = {1, 2, 3};
    int x;
    cin >> x;

    cout << minimumElements(num, x) << endl;

    return 0;
}