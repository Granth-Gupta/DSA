#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1) -> Inplace modification of array

int findDuplicate(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]) - 1;

        if (arr[index] < 0)
            return abs(arr[i]);

        arr[index] = -arr[index];
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + n);

    int duplicate = findDuplicate(v, n);

    if (duplicate != -1)
        cout << "Duplicate element is: " << duplicate << endl;
    else
        cout << "No duplicate element found" << endl;

    return 0;
}
