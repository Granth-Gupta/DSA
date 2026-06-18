// Merge K Sorted Lists - Approach 2: Using Min Heap (Priority Queue) - TC: O(N log K), SC: O(K)

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class compare
{
public:
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for(int i = 0; i < listArray.size(); i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(!minHeap.empty()){
        Node* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL){
            minHeap.push(top->next);
        }

        if(head == NULL){
            head = top;
            tail = top;
        } else {
            tail->next = top;
            tail = top;
        }
    }

    return head;
}

int main(){
    int k;
    cin >> k;
    vector<Node*> listArray(k);

    for(int i = 0; i < k; i++){
        int n;
        cin >> n;
        Node* head = NULL;
        Node* tail = NULL;

        for(int j = 0; j < n; j++){
            int data;
            cin >> data;
            Node* newNode = new Node(data);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        listArray[i] = head;
    }

    // Input
    //  3
    //  3    
    //  1 3 5
    //  2
    //  2 6
    //  1
    //  4

    // Output
    // 1 2 3 4 5 6

    Node* mergedHead = mergeKLists(listArray);

    while(mergedHead != NULL){
        cout << mergedHead->data << " ";
        mergedHead = mergedHead->next;
    }
    cout << endl;

    return 0;
}