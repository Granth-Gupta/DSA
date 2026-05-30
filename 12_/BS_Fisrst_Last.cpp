// First and Last Position of an Element In Sorted Array
// Coding Ninjas - https://www.naukri.com/code360/problems

#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector<int>& arr, int n, int k){
    int start = 0;
    int end = n-1;

    int first = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == k){
            end = mid - 1; 
            first = mid;
        }
        else if(arr[mid] < k){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return first; 
}

int lastOccurrence(vector<int>& arr, int n, int k){
    int start = 0;
    int end = n-1;

    int last = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == k){
            start = mid + 1; 
            last = mid;
        }
        else if(arr[mid] < k){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return last; 
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int, int> p;
    p.first = -1;
    p.second = -1;

    p.first = firstOccurrence(arr, n, k);
    p.second = lastOccurrence(arr, n, k);

    return p;
}

int main(){
    vector<int> arr = {0,0,1,1,2,2,2,2};
    int n = arr.size();
    int k = 3;

    pair<int, int> result = firstAndLastPosition(arr, n, k);
    cout << "First occurrence of " << k << " is at index: " << result.first << endl;
    cout << "Last occurrence of " << k << " is at index: " << result.second << endl;

    return 0;
}