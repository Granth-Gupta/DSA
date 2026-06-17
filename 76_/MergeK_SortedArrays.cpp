// Merge K sorted arrays into one sorted array - Approach 1: Using Sorting {TC: O(n log(n))} {SC: O(n)}

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    vector<int> mergedArray;
    for(int i=0; i<k; i++){
        for(int j=0; j<kArrays[i].size(); j++){
            mergedArray.push_back(kArrays[i][j]);
        }
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