#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
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

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;

    return 0;
}