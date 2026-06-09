// Morris Traversal for Preorder - SC: O(1) TC: O(N)

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root == NULL)
            return ans;

        TreeNode* current = root;

        while(current != NULL){
            if(current->left == NULL){
                ans.push_back(current->val);
                current = current->right;
            }
            else{
                TreeNode* predecessor = current->left;
                while (predecessor->right != NULL && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if(predecessor->right == NULL){
                    predecessor->right = current;

                    // In preorder, we visit the current node before its left subtree
                    // so we add it to the answer list here.
                    ans.push_back(current->val);
                    current = current->left;
                }
                else{
                    predecessor->right = NULL;
                    // In preorder, we have already visited the current node before its left subtree
                    // so we do not add it to the answer list here.
                    current = current->right;
                }
            }
        }
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> ans = sol.preorderTraversal(root);

    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}