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
    void solve(Node* root, vector<int> &path, int node){
        if(root == NULL){
            return;
        }
        
        path.push_back(root->data);
        
        if(root->data == node){
            return;
        }
        
        solve(root->left, path, node);
        solve(root->right, path, node);
    }
    
  public:
    int kthAncestor(Node *root, int k, int node) {
        vector<int> path;
        solve(root, path, node);
        
        int size = path.size();
        
        // If k is greater than or equal to the size of the path, it means the kth ancestor does not exist
        if(k >= size){
            return -1;
        }
        
        // The kth ancestor will be at index size - 1 - k in the path vector
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