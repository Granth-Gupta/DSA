#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == key){
            return mid;
        } else if(arr[mid] < key){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1; // Key not found
}

int main(){
    int arr[6] = {2,3,5,7,11,13};
    cout << "Search key: ";
    int key;
    cin >> key;

    int result = binarySearch(arr, 6, key);
    if(result != -1){
        cout << "Key is present at index: " << result << endl;
    } else {
        cout << "Key is not present in the array." << endl;
    }
    return 0;
}