// 'K' Queues in an Array (GFG)

#include <iostream>
#include<vector>
using namespace std;

class kQueues {
private:
    vector<int> arr;   
    int n, k;          
    vector<int> front; 
    vector<int> rear;  
    vector<int> next;  
    int freeIndex;          

public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;
        arr.resize(n);
        front.resize(k, -1);
        rear.resize(k, -1);
        next.resize(n);
        
        // Initialize all spaces as free
        freeIndex = 0;
        for (int i = 0; i < n-1; i++)
            next[i] = i + 1;
            
        // -1 is used to indicate end of free list
        next[n-1] = -1; 
    }
    
    // Function to check if queue 'qn' is empty
    bool isEmpty(int qn) {
        return (front[qn] == -1);
    }
    
    // Function to check if array is full
    bool isFull() {
        return (freeIndex == -1);
    }
    
    // Function to enqueue 'x' into queue 'qn'
    bool enqueue(int x, int qn) {
        
        // Check if array is full
        if (isFull())
            return false;
            
        // Get next free index
        int i = freeIndex;
        freeIndex = next[i];
        
        // If queue is empty, update 
        // both front and rear
        if (isEmpty(qn))
            front[qn] = i;
        else {
            
            // Link new element to the previous rear
            next[rear[qn]] = i; 
        }
        
        // Update rear
        rear[qn] = i;
        
        // Store the element
        arr[i] = x;
        
        // Mark end of queue
        next[i] = -1;
        
        return true;
    }
    
    // Function to dequeue from queue 'qn'
    int dequeue(int qn) {
        
        // Check if queue is empty
        if (isEmpty(qn))
            return -1;
            
        // Get the front index of queue
        int i = front[qn];
        
        // Update front
        front[qn] = next[i];
        
        // If queue becomes empty
        if (front[qn] == -1)
            rear[qn] = -1;
        
        // Add the dequeued position to free list
        next[i] = freeIndex;
        freeIndex = i;
        
        // Return the dequeued element
        return arr[i];
    }
};

int main() {
    int n = 10, k = 3;
    kQueues queues(n, k);
    
    cout << queues.enqueue(10, 0) << " "; 
    cout << queues.enqueue(20, 1) << " "; 
    cout << queues.enqueue(30, 0) << " "; 
    cout << queues.enqueue(40, 2) << " "; 
    
    cout << queues.dequeue(0) << " ";     
    cout << queues.dequeue(1) << " ";     
    cout << queues.dequeue(2) << " ";     
    cout << queues.dequeue(0) << " ";     
    cout << queues.dequeue(0) << " ";      
    
    return 0;
}