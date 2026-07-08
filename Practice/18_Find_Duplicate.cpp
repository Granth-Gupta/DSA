#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n)
{
    int ans[n] = {0};

    for (int i = 0; i < n; i++)
    {
        ans[arr[i]]++;
        if (ans[arr[i]] > 1)
            return arr[i];
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
