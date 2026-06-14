// Heapify Algorithm - TC: O(n) - Convert an array into a heap
// Heapify - TC: O(log n) - Maintain the heap property for a subtree rooted at index i, assuming the subtrees rooted at its children are already heaps

#include <iostream>
using namespace std;

// Max Heapify
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){
    // TC: O(n) - We start from the last non-leaf node and heapify each node up to the root node
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildHeap(arr, n);

    cout << "Heapified array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

