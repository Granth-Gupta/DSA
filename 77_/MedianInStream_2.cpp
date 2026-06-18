// Median in a stream. - CN - Approach 2 - Using signum(), MinHeap and MaxHeap {TC: O(n log n), SC: O(n)}

#include <bits/stdc++.h>
using namespace std;

int signum(int x){
    if(x > 0) 
        return 1;
    else if(x < 0) 
        return -1;
    else 
        return 0;
}

void callMedian(int x, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int &median){
    switch (signum(maxHeap.size() - minHeap.size())) {
        case 0: 
            if (x < median) {
                maxHeap.push(x);
                median = maxHeap.top();
            } 
            else {
                minHeap.push(x);
                median = minHeap.top();
            }
            break;

        case 1: 
            if (x < median) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            } 
            else {
                minHeap.push(x);
            }
            median = (maxHeap.top() + minHeap.top()) / 2;
            break;

        case -1:
            if (x > median) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
            } 
            else {
                maxHeap.push(x);
            }
            median = (maxHeap.top() + minHeap.top()) / 2;
            break;
    }
}

vector<int> findMedian(vector<int> &arr, int n){
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = -1;

    for(int i = 0; i < n; i++){
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}

int main(){
    vector<int> arr = {5, 15, 1, 3};
    int n = arr.size();
    vector<int> medians = findMedian(arr, n);

    for(int i = 0; i < medians.size(); i++){
        cout << medians[i] << " ";
    }
    cout << endl;

    return 0;
}