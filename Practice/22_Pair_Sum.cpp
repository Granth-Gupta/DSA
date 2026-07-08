#include <bits/stdc++.h>
using namespace std;

int pairSum(vector<int> &arr, int n, int target)
{
    int count = 0;
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        int val = arr[start] + arr[end];

        if (val == target)
        {
            count++;
            start++;
            end--;
        }
        else if (val < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    return (count == 0) ? -1 : count;
}

int main()
{
    int n, target;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> arr(n);
    cout << "Enter the elements in ascending order: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The number of pairs with sum " << target << " is: ";
    cout << pairSum(arr, n, target) << endl;

    return 0;
}