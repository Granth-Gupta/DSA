// Two sum in a BST - CN {TC: O(n) SC: O(n)}

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

    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        int i = 0, j = v.size() - 1;
        while(i < j){
            int sum = v[i] + v[j];
            if(sum == k) return true;
            else if(sum < k) i++;
            else j--;
        }
        return false;
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
    int k = 9;
    cout << sol.findTarget(root, k) << endl; // Output: true

    return 0;
}

