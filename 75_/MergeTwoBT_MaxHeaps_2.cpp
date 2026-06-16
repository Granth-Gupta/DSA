// Merge two bianry trees into a max heap - GFG - Approach 2: using heapify - TC: O(n) - SC: O(n)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    vector<int> mergedHeap(n + m);
    for(int i = 0; i < n; i++) {
        mergedHeap[i] = arr1[i];
    }
    for(int i = 0; i < m; i++) {
        mergedHeap[n + i] = arr2[i];
    }

    for(int i = (n + m) / 2 - 1; i >= 0; i--) {
        heapify(mergedHeap, n + m, i);
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

