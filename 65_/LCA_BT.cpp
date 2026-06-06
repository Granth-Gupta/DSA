// Lowest Common Ancestor of a Binary Tree - GFG

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(root == NULL)
            return NULL;
            
        if(n1 == root || n2 == root)
            return root;
            
        Node* leftAns = LCA(root->left, n1, n2);
        Node* rightAns = LCA(root->right, n1, n2);
        
        if(leftAns != NULL && rightAns != NULL)
            return root;
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
        else
            return NULL;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    
    Solution sol;
    Node* ans = sol.LCA(root, root->left->left, root->left->right);
    
    if(ans != NULL)
        cout << "LCA: " << ans->data << endl;
    else
        cout << "LCA does not exist." << endl;
    
    return 0;
}