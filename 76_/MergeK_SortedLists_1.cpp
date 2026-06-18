// Merge K Sorted Lists - Approach 1: Using Sorting - TC: O(NK log(NK)), SC: O(NK)

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

Node* mergeKLists(vector<Node*> &listArray){
    vector<int> mergedList;

    for(int i = 0; i < listArray.size(); i++){
        Node* temp = listArray[i];
        while(temp != NULL){
            mergedList.push_back(temp->data);
            temp = temp->next;
        }
    }

    sort(mergedList.begin(), mergedList.end());

    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0; i < mergedList.size(); i++){
        Node* newNode = new Node(mergedList[i]);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}

int main(){
    // Example usage
    Node* list1 = new Node(1, new Node(4, new Node(5)));
    Node* list2 = new Node(1, new Node(3, new Node(4)));
    Node* list3 = new Node(2, new Node(6));

    vector<Node*> lists = {list1, list2, list3};

    Node* mergedHead = mergeKLists(lists);

    // Print merged list
    Node* temp = mergedHead;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}