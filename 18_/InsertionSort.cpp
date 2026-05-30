#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int n, vector<int> &arr){

    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;

        for(; j>=0; j--){

            if(arr[j] > key){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = key;
    }
}

int main(){
    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();

    insertionSort(n, arr);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}