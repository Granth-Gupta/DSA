// Morris Traversal for Inorder - SC: O(1) TC: O(N)

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
    vector<int> inorderTraversal(TreeNode* root) {
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
                    current = current->left;
                }
                else{
                    predecessor->right = NULL;
                    ans.push_back(current->val);
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
    vector<int> result = sol.inorderTraversal(root);

    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}