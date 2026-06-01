// Count number of leaf nodes in a binary tree (CN)

#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

node* buildTree(node* root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

int countLeafNodes(node* root){
    if(root == NULL){
        return 0;
    }

    if(root -> left == NULL && root -> right == NULL){
        return 1;
    }

    int leftLeafNodes = countLeafNodes(root -> left);
    int rightLeafNodes = countLeafNodes(root -> right);

    return leftLeafNodes + rightLeafNodes;
}

int main(){
    node* root = NULL;
    root = buildTree(root); // 1 3 7 -1 -1  11 -1 -1 5 17 -1 -1 -1

    int leafNodes = countLeafNodes(root);
    cout << "Number of leaf nodes: " << leafNodes << endl;
    
    return 0;
}
