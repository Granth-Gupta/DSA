// Ninja's Training - Approach 3: Bottom-Up DP
// TC: O(n) SC: O(n)

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        int option1 = cost[0] + dp[k + 1];

        int i;
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;
        int option2 = cost[1] + dp[i];

        for (i = k; i < n && days[i] < days[k] + 30; i++)
            ;
        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }

    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n, days, cost);
}

int main()
{
    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    vector<int> days(n);
    cout << "Enter the days: ";
    for (int i = 0; i < n; i++)
        cin >> days[i];

    vector<int> cost(3);
    cout << "Enter the cost of 1-day, 7-day, and 30-day passes: ";
    for (int i = 0; i < 3; i++)
        cin >> cost[i];

    cout << "Minimum cost of tickets: ";
    cout << minimumCoins(n, days, cost) << endl;

    return 0;
}