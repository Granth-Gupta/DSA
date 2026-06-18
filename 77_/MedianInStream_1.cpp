// Median in a stream. - CN - Approach 1 - Using insertion sort {TC: O(n^2), SC: O(1)}

// Since the stream is sorted, we can use insertion sort to insert the new element in the correct position. This will take O(n) time for each insertion. 
// For other sorting algorithms like quicksort or mergesort, we would have to sort the entire array again which would take O(n log n) time.

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &stream, int val){
    stream.push_back(val);
    int i = stream.size() - 2;

    while(i >= 0 && stream[i] > val){
        swap(stream[i], stream[i + 1]);
        i--;
    }
}

vector<int> findMedian(vector<int> &arr, int n){
    vector<int> medians;
    vector<int> stream;

    for(int i = 0; i < n; i++){
        insertionSort(stream, arr[i]);

        if(stream.size() % 2 == 0){
            medians.push_back((stream[stream.size()/2] + stream[stream.size()/2 - 1]) / 2);
        } 
        else {
            medians.push_back(stream[stream.size()/2]);
        }
    }
    return medians;
}

int main(){
    vector<int> arr = {5, 15, 1, 3};
    int n = arr.size();
    vector<int> medians = findMedian(arr, n);

    for(int i = 0; i < medians.size(); i++){
        cout << medians[i] << " ";
    }
    cout << endl;

    return 0;
}   