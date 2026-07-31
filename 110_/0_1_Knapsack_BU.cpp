// 0/1 Knapsack Problem using Bottom Up Dynamic Programming approach
// TC : O(n*W) where n is the number of items and W is the maximum weight of the knapsack
// SC : O(n*W) for dp array

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int incl = 0;
            if (weight[index] <= w)
                incl = value[index] + dp[index - 1][w - weight[index]];

            int excl = dp[index - 1][w];

            dp[index][w] = max(incl, excl);
        }
    }
    return dp[n - 1][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n, maxWeight);
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