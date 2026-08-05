// Ninja's Training - Approach 4: Space optimization using queue (sliding window technique)
// TC: O(n)
// SC: O(7 + 30) = O(1)

#include <bits/stdc++.h>
using namespace std;

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    int ans = 0;

    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for (int day : days)
    {

        // step 1: remove expired days
        while (!month.empty() && month.front().first + 30 <= day)
            month.pop();
        while (!week.empty() && week.front().first + 7 <= day)
            week.pop();

        // step 2: add cost for current day
        month.push(make_pair(day, ans + cost[2]));
        week.push(make_pair(day, ans + cost[1]));

        // step 3: ans update
        ans = min(ans + cost[0], min(month.front().second, week.front().second));
    }
    return ans;
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