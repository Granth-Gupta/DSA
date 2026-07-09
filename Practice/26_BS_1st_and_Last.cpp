#include <bits/stdc++.h>
using namespace std;

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    int last = upper_bound(arr.begin(), arr.end(), k) - arr.begin() - 1;

    if (first == n || arr[first] != k)
        return {-1, -1};

    return {first, last};
}

int main()
{
    int n = 5;
    vector<int> arr = {1, 2, 2, 2, 3};
    int k = 2;

    pair<int, int> result = firstAndLastPosition(arr, n, k);

    cout << "The first occurrence of " << k << " is at index: " << result.first << endl;
    cout << "The last occurrence of " << k << " is at index: " << result.second << endl;

    return 0;
}