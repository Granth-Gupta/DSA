#include <iostream>
#include <algorithm>
using namespace std;

int partition(int* arr, int s, int e){
    int pivot = arr[s];

    int count = 0;
    for(int i=s+1; i<=e; i++){
        if (arr[i] <= pivot){
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if (i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void QuickSort(int* arr, int s, int e){
    if (s >= e){
        return;
    }

    int pivotIndex = partition(arr, s, e);
    QuickSort(arr, s, pivotIndex-1);
    QuickSort(arr, pivotIndex+1, e);
}

int main(){
    int arr[10] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6};

    cout << "Before Sorting: ";
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }

    QuickSort(arr, 0, 9);

    cout << "\nAfter Sorting: ";
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }

    return 0;
}