// Minimum cost of ropes - GFG - Approach: using min heap - TC: O(nlogn) - SC: O(n)

#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for(long long i = 0; i < n; i++){
        minHeap.push(arr[i]);
    }

    long long totalCost = 0;
    while(minHeap.size() > 1){
        long long first = minHeap.top();
        minHeap.pop();
        long long second = minHeap.top();
        minHeap.pop();

        long long cost = first + second;
        totalCost += cost;
        minHeap.push(cost);
    }

    return totalCost;
}

int main(){
    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr) / sizeof(arr[0]);
    cout << minCost(arr, n) << endl; // Output: 29

    return 0;
}
