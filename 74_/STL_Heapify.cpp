// STL for Heapify - priority_queue (#include <queue>) 

#include <iostream>
#include <queue>
using namespace std;

int main(){
    // Max Heap using priority_queue
    priority_queue<int> maxHeap;

    maxHeap.push(1);
    maxHeap.push(2);
    maxHeap.push(3);
    maxHeap.push(4);
    maxHeap.push(5);
    maxHeap.pop(); 

    cout << "Max Heap top element: " << maxHeap.top() << endl; // 5

    // Min Heap using priority_queue with greater<int>
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(1);
    minHeap.push(2);
    minHeap.push(3);
    minHeap.push(4);
    minHeap.push(5);

    cout << "Min Heap top element: " << minHeap.top() << endl; // 1

    return 0;
}