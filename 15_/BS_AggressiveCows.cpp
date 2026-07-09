#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC: O(nlogn)

bool isPossible(vector<int> &stalls, int mid, int k, int n)
{
    int countcows = 1;
    int nextcow = 0;

    for (int i = 0; i < n; i++)
    {
        if (countcows > k)
        {
            break;
        }

        if (stalls[i] - stalls[nextcow] >= mid)
        {
            countcows++;
            nextcow = i;
        }
    }

    if (countcows < k)
    {
        return false;
    }

    return true;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int ans = -1;
    int n = stalls.size();

    int s = 0;
    int e = stalls[n - 1] - stalls[0];
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (isPossible(stalls, mid, k, n))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;

    int ans = aggressiveCows(stalls, k);
    cout << "The largest minimum distance is: " << ans << endl;

    return 0;
}