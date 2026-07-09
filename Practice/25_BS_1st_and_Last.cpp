// Binary search first and last occurrence of an element in a sorted array

#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= k)
        {
            end = mid - 1; // Move left to find the first occurrence
        }
        else
        {
            start = mid + 1;
        }
    }

    if (start < n && arr[start] == k)
    {
        return start;
    }
    return -1;
}

int lastOccurrence(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] <= k)
        {
            start = mid + 1; // Move right to find the last occurrence
        }
        else
        {
            end = mid - 1;
        }
    }

    if (end >= 0 && arr[end] == k)
    {
        return end;
    }
    return -1;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    pair<int, int> p;
    p.first = -1;
    p.second = -1;

    p.first = firstOccurrence(arr, n, k);
    p.second = lastOccurrence(arr, n, k);

    return p;
}

int main()
{
    int n, k;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements in ascending order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the key to find its first and last occurrence: ";
    cin >> k;

    pair<int, int> result = firstAndLastPosition(arr, n, k);

    if (result.first == -1 && result.second == -1)
    {
        cout << "The key " << k << " is not present in the array." << endl;
    }
    else
    {
        cout << "The first occurrence of " << k << " is at index: " << result.first << endl;
        cout << "The last occurrence of " << k << " is at index: " << result.second << endl;
    }

    return 0;
}