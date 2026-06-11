// Normal BST To Balanced BST - CN {TC: O(n) SC: O(n)}

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
        if(root == NULL) 
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    TreeNode* buildTree(vector<int>& v, int start, int end){
        if(start > end) 
            return NULL;

        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(v[mid]);

        node->left = buildTree(v, start, mid - 1);
        node->right = buildTree(v, mid + 1, end);

        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return buildTree(v, 0, v.size() - 1);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* newRoot = sol.balanceBST(root);

    queue<TreeNode*> q;
    q.push(newRoot);

    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        
        cout << curr->val << " ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    cout << endl; // Output: 2 1 3 4

    return 0;
}