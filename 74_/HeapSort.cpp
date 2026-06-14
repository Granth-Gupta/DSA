// Heap sort - TC: O(n log n) - Space Complexity: O(1) - 1-based indexing

#include <iostream>
using namespace std;

// Heapify using 1-based indexing

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    // Build Max Heap
    for(int i = n / 2; i >= 1; i--){
        heapify(arr, n, i);
    }

    // One by one extract elements from heap
    while(n > 1){
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main(){
    int arr[] = {-1, 5, 4, 3, 2, 1}; // 1-based indexing
    int n = sizeof(arr) / sizeof(arr[0]) - 1; // Exclude the first element

    heapSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}