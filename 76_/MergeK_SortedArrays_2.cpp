// Merge K sorted arrays into one sorted array - Approach 2: Using Min Heap {TC: O(n log(k))} {SC: O(k)}

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    
        vector<int> mergedArray;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
    
        for(int i=0; i<k; i++){
            if(!kArrays[i].empty()){
                minHeap.push({kArrays[i][0], {i, 0}});
            }
        }
    
        while(!minHeap.empty()){
            auto top = minHeap.top();
            minHeap.pop();
            int value = top.first;
            int arrayIndex = top.second.first;
            int elementIndex = top.second.second;
    
            mergedArray.push_back(value);
    
            if(elementIndex + 1 < kArrays[arrayIndex].size()){
                minHeap.push({kArrays[arrayIndex][elementIndex + 1], {arrayIndex, elementIndex + 1}});
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