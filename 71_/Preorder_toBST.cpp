// Preorder traversal of a BST - CN {TC: O(n) SC: O(n)}

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
    TreeNode* buildTree(vector<int>& preorder, int& index, int min, int max){
        if(index >= preorder.size()) 
            return NULL;

        int val = preorder[index];
        if(val < min || val > max) 
            return NULL;

        TreeNode* node = new TreeNode(val);
        index++;

        node->left = buildTree(preorder, index, min, val);
        node->right = buildTree(preorder, index, val, max);

        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildTree(preorder, index, INT_MIN, INT_MAX);
    }
};

int main(){
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    // Print the values of the tree in inorder traversal
    stack<TreeNode*> s;
    TreeNode* curr = root;

    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl; // Output: 1 5 7 8 10 12

    return 0;
}
