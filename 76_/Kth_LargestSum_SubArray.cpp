// Kth Largest Sum of Subarray - Coding Ninjas - Approach #1: Sort and 2 loops {TC: O(n^2 log(n^2))} {SC: O(n^2)}

#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> sumArr;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            sumArr.push_back(sum);
        }
    }

    sort(sumArr.begin(), sumArr.end(), greater<int>());

    return sumArr[k - 1];
}

int main()
{
    vector<int> arr = {3, 2, 1, 4, 5};
    int k = 3;
    cout << getKthLargest(arr, k) << endl; // Output: 9
    return 0;
}   