// 0/1 Knapsack Problem using Brute Force approach
// TC: O(2^n) where n is the number of items
// SC: O(n) for recursion stack space

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    int incl = 0;
    if (weight[index] <= capacity)
        incl = value[index] + solve(weight, value, index - 1, capacity - weight[index]);

    int excl = solve(weight, value, index - 1, capacity);

    int ans = max(incl, excl);

    return ans;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n - 1, maxWeight);
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