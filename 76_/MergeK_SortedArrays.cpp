// Merge K sorted arrays into one sorted array - Approach 1: Using Sorting {TC: O(n log(n))} {SC: O(n)}

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &arrays)
{
    vector<int> mergedArray;

    for (const auto &arr : arrays)
    {
        mergedArray.insert(mergedArray.end(), arr.begin(), arr.end());
    }

    sort(mergedArray.begin(), mergedArray.end());

    return mergedArray;
}

int main()
{
    vector<vector<int>> arrays = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    vector<int> mergedArray = mergeKSortedArrays(arrays);

    for (int num : mergedArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}