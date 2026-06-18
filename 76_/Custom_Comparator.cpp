// Custom Comparator - Priority Queue (Operator Overloading) 

#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        int row;
        int col;

        Node(int d, int r, int c){
            this->data = d;
            this->row = r;
            this->col = c;
        }
};

// Custom Comparator for Min Heap

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

int main(){
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // greater<dataType> is a built-in comparator that can be used to create a min heap for primitive data types like int, float, etc.

    Node* n1 = new Node(10, 0, 0);
    Node* n2 = new Node(5, 1, 0);
    Node* n3 = new Node(20, 2, 0);

    minHeap.push(n1);
    minHeap.push(n2);
    minHeap.push(n3);

    while(!minHeap.empty()){
        Node* temp = minHeap.top();
        minHeap.pop();
        cout << temp->data << " ";
    }
    cout << endl;

    return 0;
}
