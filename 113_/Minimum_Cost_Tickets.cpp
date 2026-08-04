// Ninja's Trip - CN (Approach 1: Simple recursion)
// TC: O(3^n) SC: O(n)

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &days, vector<int> &cost, int index)
{
    if (index >= n)
        return 0;

    int option1 = cost[0] + solve(n, days, cost, index + 1);

    int i;
    for (i = index; i <= n && days[i] < days[index] + 7; i++)
        ;
    int option2 = cost[1] + solve(n, days, cost, i);

    for (i = index; i <= n && days[i] < days[index] + 30; i++)
        ;
    int option3 = cost[2] + solve(n, days, cost, i);

    return min(option1, min(option3, option2));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n, days, cost, 0);
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