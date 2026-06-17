// Merge two bianry trees into a max heap - GFG - Approach: using priority queue - TC: O(nlogn) - SC: O(n)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    priority_queue<int> maxHeap;

    for(int i = 0; i < n; i++){
        maxHeap.push(arr1[i]);
    }

    for(int i = 0; i < m; i++){
        maxHeap.push(arr2[i]);
    }

    vector<int> mergedHeap;
    while(!maxHeap.empty()){
        mergedHeap.push_back(maxHeap.top());
        maxHeap.pop();
    }

    return mergedHeap;
}

int main(){
    int n = 5, m = 4;
    vector<int> arr1 = {10, 5, 6, 2, 3};
    vector<int> arr2 = {12, 7, 9, 1};

    vector<int> mergedHeap = mergeHeap(n, m, arr1, arr2);

    for(int i = 0; i < mergedHeap.size(); i++){
        cout << mergedHeap[i] << " ";
    }
    cout << endl;

    return 0;
}