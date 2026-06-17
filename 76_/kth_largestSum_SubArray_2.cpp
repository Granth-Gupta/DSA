// Kth Largest sum of Subarray - Coding Ninjas - Approach #2: Min Heap {TC: O(n^2 log(k))} {SC: O(k)}

#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            minHeap.push(sum);

            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
    }

    return minHeap.top();
}

int main()
{
    vector<int> arr = {3, 2, 1, 4, 5};
    int k = 3;
    cout << getKthLargest(arr, k) << endl; // Output: 9
    return 0;
}
