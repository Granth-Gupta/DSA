// Kth Ancestor of a Binary Tree - GFG (Approach#2 - using vector to store path)
// TC: O(H) where H is the height of the tree (in worst case, when the tree is skewed)
// SC: O(H) where H is the height of the tree (due to recursion stack) + O(H) for the path vector

#include <iostream>
#include <vector>
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
    bool solve(Node* root, vector<int> &path, int node){
        if(root == NULL){
            return false;
        }
        
        path.push_back(root->data);
        
        if(root->data == node){
            return true;
        }
        
        if(solve(root->left, path, node) || solve(root->right, path, node)) {
            return true;
        }
        
        path.pop_back();
        return false;
    }
    
  public:
    int kthAncestor(Node *root, int k, int node) {
        vector<int> path;
        solve(root, path, node);
        
        int size = path.size();
        
        if(k >= size){
            return -1;
        }
        
        return path[size - 1 - k];
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    Solution sol;
    int k = 1;
    int node = 4;
    int ans = sol.kthAncestor(root, k, node);
    
    if(ans != -1)
        cout << "Kth Ancestor: " << ans << endl;
    else
        cout << "Kth Ancestor does not exist." << endl;
    
    return 0;
}