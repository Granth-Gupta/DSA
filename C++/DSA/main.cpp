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
};

void insertAtHead(Node *&head,int data){
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

int main(){
    Node *n = new Node(10);
    Node *head = n;

    insertAtHead(head,15);
    insertAtHead(head,20);
    insertAtHead(head,25);
    insertAtHead(head,30);

    return 0;
}
