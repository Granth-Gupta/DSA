// Maximum Non-Adjacent Nodes Sum - GFG 
// TC: O(N) where N is the number of nodes in the tree (each node is visited once)
// SC: O(H) where H is the height of the tree (due to recursion stack)

#include <iostream>
#include <algorithm>
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
    pair<int, int> solve(Node* root){
        if(root == NULL){
            return make_pair(0,0);
        }
        
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        pair<int, int> res;
        
        res.first = root->data + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
    }
  public:
    int getMaxSum(Node *root) {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    
    Solution sol;
    int ans = sol.getMaxSum(root);
    
    cout << "Maximum sum of non-adjacent nodes: " << ans << endl;
    
    return 0;
}