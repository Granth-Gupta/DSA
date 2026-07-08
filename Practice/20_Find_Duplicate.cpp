// Find Duplicate in an array using Hare and Tortoise Algorithm (Floyd's Cycle Detection Algorithm)

// TC: O(n) SC: O(1) -> No extra space used -> No Inplace modification of array (Thus slower than previous approach)

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n)
{
    int slow = arr[0];
    int fast = arr[0];

    // Step 1: Find the intersection point of the two runners.
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    // Step 2: Find the entrance to the cycle.
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
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
