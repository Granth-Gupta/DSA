// Kth smallest element - GFG - Approach: using heap - TC: O(nlogk) - SC: O(k)
// Why TC is O(nlogk): 
// We are iterating through the array of size n and for each element,
// we are performing a push and pop operation on the heap which takes logk time. Hence, the overall time complexity is O(nlogk).

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> maxHeap;

        for(int i = 0; i < k; i++){
            maxHeap.push(arr[i]);
        }

        for(int i = k; i < arr.size(); i++){
            if(arr[i] < maxHeap.top()){
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }

        return maxHeap.top();
    }
};

int main(){
    Solution s;
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << s.kthSmallest(arr, k) << endl; // Output: 7

    return 0;
}