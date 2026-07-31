// 0/1 Knapsack Problem using Bottom Up + Space Optimization Dynamic Programming approach
// TC : O(n*W) where n is the number of items and W is the maximum weight of the knapsack
// SC : O(2W) ~ O(w) for prev and curr arrays

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int incl = 0;
            if (weight[index] <= w)
                incl = value[index] + prev[w - weight[index]];

            int excl = prev[w];

            curr[w] = max(incl, excl);
        }
        prev = curr;
    }
    return prev[capacity];
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