// Merge K sorted arrays into one sorted array - Approach 2: Using Min Heap {TC: O(n log(k))} {SC: O(k)}

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &arrays)
{
    vector<int> mergedArray;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

    for (int i = 0; i < arrays.size(); i++)
    {
        if (!arrays[i].empty())
        {
            minHeap.push({arrays[i][0], {i, 0}});
        }
    }

    while (!minHeap.empty())
    {
        auto top = minHeap.top();
        minHeap.pop();

        int value = top.first;
        int arrayIndex = top.second.first;
        int elementIndex = top.second.second;

        mergedArray.push_back(value);

        if (elementIndex + 1 < arrays[arrayIndex].size())
        {
            minHeap.push({arrays[arrayIndex][elementIndex + 1], {arrayIndex, elementIndex + 1}});
        }
    }

    return mergedArray;
}

int main(){
    vector<vector<int>> arrays = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    vector<int> mergedArray = mergeKSortedArrays(arrays);

    for (int num : mergedArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}