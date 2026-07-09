#include <iostream>
#include <vector>
using namespace std;

// TC: O(nlogn) SC: O(1)

bool isPossible(vector<int> &arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pagesum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pagesum + arr[i] <= mid)
        {
            pagesum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pagesum = arr[i];
        }
    }

    return true;
}

int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
    {
        return -1;
    }

    int s = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size();
    int m = 2;

    int ans = findPages(arr, n, m);
    cout << "Minimum number of pages: " << ans << endl;

    return 0;
}