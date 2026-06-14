// Building Min Heap using Heapify Algorithm - TC: O(n) - Coding Ninjas 

#include <iostream>
using namespace std;

// Min Heapify
void minHeapify(int arr[], int n, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }

    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n){
    // TC: O(n) - We start from the last non-leaf node and heapify each node up to the root node
    for(int i = n / 2 - 1; i >= 0; i--){
        minHeapify(arr, n, i);
    }
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMinHeap(arr, n);

    cout << "Min Heapified array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

