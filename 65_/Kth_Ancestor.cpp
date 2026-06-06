// Kth ancestor of a tree node - GFG (Approach #1 - using recursion)
// TC: O(H) where H is the height of the tree (in worst case, when the tree is skewed)
// SC: O(H) where H is the height of the tree (due to recursion stack)

#include <iostream>
#include <climits>
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
    Node* solve(Node* root, int &k, int node) {
        // Base Cases
        if (root == NULL)
            return NULL;
            
        if (root->data == node)
            return root;
            
        // Look for the node in left and right subtrees
        Node* leftAns = solve(root->left, k, node);
        Node* rightAns = solve(root->right, k, node);
        
        // If the node was found in either subtree, we are on the ancestor path
        if (leftAns != NULL || rightAns != NULL) {
            k--; // Move one ancestor up
            if (k == 0) {
                // Lock k so higher levels don't overwrite this node
                k = INT_MAX; 
                return root;
            }
            // Pass the found target node or an ancestor up the call stack
            return (leftAns != NULL) ? leftAns : rightAns;
        }
        
        return NULL;
    }
    
  public:
    int kthAncestor(Node *root, int k, int node) {
        Node* ans = solve(root, k, node);
        
        // If ans is NULL or it returned the target node itself, 
        // it means the kth ancestor doesn't exist (k went out of bounds)
        if (ans == NULL || ans->data == node)
            return -1;
            
        return ans->data;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    Solution sol;
    int k = 2;
    int node = 5;
    int ans = sol.kthAncestor(root, k, node);
    
    if(ans != -1)
        cout << "Kth Ancestor: " << ans << endl;
    else
        cout << "Kth Ancestor does not exist." << endl;
    
    return 0;
}   