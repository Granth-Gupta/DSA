#include <iostream>
using namespace std;

int findPivot(int* arr, int n){
    int s = 0;
    int e = n-1;

    int mid = s + (e-s)/2;

    while(s < e){
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }

    return s;
}

int search(int* arr, int n, int key) {
    int pivot = findPivot(arr, n);

    int s = 0;
    int e = n-1;

    if((key <= arr[n-1]) && (key >= arr[pivot])){
        s = pivot;
    }
    else{
        e = pivot - 1;
    }

    int mid = s + (e-s)/2;

    while(s <= e){
        if(arr[mid] == key){
            return mid;
        }
        
        if(arr[mid] < key){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    
    return -1;
}

int main(){
    int arr[5] = {7,9,1,2,3}; // Pivot -> 1 here
    int key = 2;
    int ans = search(arr, 5, key);
    cout << "Key is at index: " << ans << endl;
}