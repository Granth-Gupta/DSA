// Boundary Traversal of a Binary Tree - GFG

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
  private:
    void addLeftBoundary(Node* root, vector<int> &ans){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            addLeftBoundary(root->left, ans);
        }
        else{
            addLeftBoundary(root->right, ans);
        }
    }
    void addRightBoundary(Node* root, vector<int> &ans){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        if(root->right){
            addRightBoundary(root->right, ans);
        }
        else{
            addRightBoundary(root->left, ans);
        }
        
        ans.push_back(root->data);
    }
    void addLeaves(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        if(root->left){
            addLeaves(root->left, ans);
        }
        if(root->right){
            addLeaves(root->right, ans);
        }
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        ans.push_back(root->data);
        
        addLeftBoundary(root->left, ans);
        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
        addRightBoundary(root->right, ans);

        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<int> result = sol.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}