// 0/1 Knapsack Problem using Top Down Dynamic Programming approach
// TC: O(n*W) where n is the number of items and W is the maximum weight of the knapsack
// SC: O(n*W) for dp array + O(n) for recursion stack space

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    int incl = 0;
    if (weight[index] <= capacity)
        incl = value[index] + solve(weight, value, index - 1, capacity - weight[index], dp);

    int excl = solve(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(incl, excl);

    return dp[index][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(weight, value, n - 1, maxWeight, dp);
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weight(n);
    vector<int> value(n);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    int maxWeight;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> maxWeight;

    cout << "The maximum value in the knapsack is: ";
    cout << knapsack(weight, value, n, maxWeight) << endl;

    return 0;
}