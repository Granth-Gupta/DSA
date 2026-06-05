// Right View of a Binary Tree - GFG (Approach 2 - Recursion / DFS)
// TC: O(N) where N is the number of nodes in the tree
// SC: O(H) where H is the height of the tree (due to recursion stack) + O(N) for the result vector

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
    void solve(Node* root, vector<int> &ans, int level){
        if(root == NULL){
            return;
        }
        
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        
        if(root->right){
            solve(root->right, ans, level+1);
        }
        
        if(root->left){
            solve(root->left, ans, level+1);
        }
    }
  public:
    vector<int> rightView(Node *root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
    Solution sol;
    vector<int> rightViewNodes = sol.rightView(root);
    
    cout << "Right View of the Binary Tree: ";
    for(int val : rightViewNodes){
        cout << val << " ";
    }
    
    return 0;
}