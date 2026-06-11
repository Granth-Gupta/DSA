// Flatten BST to sorted list - CN {TC: O(n) SC: O(n)}
// Using Morris Traversal - TC: O(n) SC: O(1)

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v){
        if(root == NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        TreeNode* newRoot = new TreeNode(v[0]);
        TreeNode* curr = newRoot;
        for(int i = 1; i < v.size(); i++){
            curr->right = new TreeNode(v[i]);
            curr = curr->right;
        }
        return newRoot;
    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution sol;
    TreeNode* newRoot = sol.increasingBST(root);

    // Print the values of the new tree
    TreeNode* curr = newRoot;
    while(curr != NULL){
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl; // Output: 2 3 4 5 6 7

    return 0;
}

