// Sum Tree - GFG
// A Sum Tree is a Binary Tree where the value of each node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also considered a Sum Tree and the sum of an empty tree can be considered as 0. A leaf node is also considered a Sum Tree.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    pair<bool, int> isSumTreeFast(Node* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL){
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool, int> leftSum = isSumTreeFast(root -> left);
        pair<bool, int> rightSum = isSumTreeFast(root -> right);
        
        bool left = leftSum.first;
        bool right = rightSum.first;
        bool cpm = root->data == leftSum.second + rightSum.second;
        
        pair<bool, int> ans;
        
        if(left && right && cpm){
            ans.first = true;
            ans.second = 2*root->data;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
  public:
    bool isSumTree(Node* root) {
        return isSumTreeFast(root).first;
    }
};

int main(){
    Node *root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    Solution ob;
    if(ob.isSumTree(root)) {
        cout << "The tree is a Sum Tree." << endl;
    } else {
        cout << "The tree is not a Sum Tree." << endl;
    }

    return 0;
}