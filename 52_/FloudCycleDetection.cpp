// Try Q:  Detect and Remove Loop (Coding Ninjas)

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

Node* startingPoint(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            break;
        }
    }

    if(fast == NULL || fast->next == NULL){
        return NULL; // No cycle
    }

    slow = head;

    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // Starting point of the cycle
}

bool detectCycle(Node* head){
    if(head == NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }

    return false;
}

int main(){
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creating a cycle

    if(detectCycle(node1)){
        cout << "Cycle detected in the linked list." << endl;

        Node* cycleStart = startingPoint(node1);
        if(cycleStart != NULL){
            cout << "The cycle starts at node with data: " << cycleStart->data << endl;
        }

    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}