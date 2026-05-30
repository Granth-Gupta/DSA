#include <iostream>
using namespace std;

void merge(int* arr, int s, int e){
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* left = new int[len1];
    int* right = new int[len2];

    for(int i=0; i<len1; i++){
        left[i] = arr[s+i];
    }
    for(int i=0; i<len2; i++){
        right[i] = arr[mid+1+i];
    }

    int i=0, j=0, k=s;

    while(i < len1 && j < len2){
        if(left[i] < right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }

    while(i < len1){
        arr[k++] = left[i++];
    }
    while(j < len2){
        arr[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

void mergesort(int* arr, int s, int e){
    if(s >= e)
        return;
    
    int mid = s + (e-s)/2;

    mergesort(arr, s, mid);
    mergesort(arr, mid+1, e);
    merge(arr, s, e);
}

int main(){
    int arr[10] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6};
    cout << "Original Array: ";
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    mergesort(arr, 0, 9);

    cout << "Sorted Array: ";
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }

    return 0;
}