// Reversed list in groups of k (Coding Ninjas)

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            int value = this->data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout << "Memory is free for node with data " << value << endl;
        }
};

Node* reverse(Node* &head, int k, int length){
    if(head == NULL)
        return NULL;

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    if(length/k != 0){
        while(count < k && length/k != 0){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        length = length - k;
    }

    if(length/k == 0){
        head->next = curr;
    }
    else{
        head->next = reverse(next, k, length);
    }
    return prev;
}

int klength(Node* head, int k){
    if(head == NULL){
        return 0;
    }
    int length = 1;

    while(head->next != NULL){
        length++;
        head = head->next;
    }
    return length;
}

Node* kReverse(Node* head, int k) {
    int length = klength(head, k);
    return reverse(head, k, length);
}

int main(){
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);
    Node* node5 = new Node(50);
    Node* node6 = new Node(60);
    Node* node7 = new Node(70);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    cout << "Original list: ";
    Node* temp = node1;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    int k = 3;

    Node* newHead = kReverse(node1, k);

    cout << "Reversed list in groups of " << k << ": ";
    while(newHead != NULL){
        cout << newHead->data << " ";
        newHead = newHead->next;
    }
    
    return 0;
}