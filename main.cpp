#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int isPossible(int arr[], int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] > mid)
        {
            studentCount++;
            pageSum = arr[i];

            if (studentCount > m)
                return -1;
        }
        else
        {
            pageSum += arr[i];
        }
    }

    return pageSum;
}

int BookAllocation(int arr[], int n, int m)
{
    if (m > n)
        return -1;

    sort(arr, arr + n);

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int s = arr[n - 1];
    int e = sum;
    int result = -1;
    vector<int> allocation;
    int mid = s + (e - s) / 2;

    cout << "Initial search space: s = " << s << ", e = " << e << endl;

    while (s <= e)
    {
        int pageSum = isPossible(arr, n, m, mid);
        cout << "Page sum for mid " << mid << ": " << pageSum << endl;
        if (pageSum != -1)
        {
            allocation.push_back(mid);
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    sort(allocation.begin(), allocation.end());
    result = allocation[0];

    return result;
}

int main()
{
    int arr[4] = {10, 20, 30, 40};
    int n = 2;

    int result = BookAllocation(arr, 4, n);
    cout << "Minimum number of pages allocated: " << result << endl;

    return 0;
}