// Morris Traversal for Postorder - SC: O(1) TC: O(N)

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        TreeNode* current = root;
        
        while(current != NULL){
            if(current->right == NULL){
                ans.push_back(current->val);
                current = current->left;
            }
            else{
                TreeNode* predecessor = current->right;
                while (predecessor->left != NULL && predecessor->left != current) {
                    predecessor = predecessor->left;
                }
                
                if(predecessor->left == NULL){
                    predecessor->left = current;
                    
                    // In postorder, we visit the current node after its right subtree
                    // so we add it to the answer list here.
                    ans.push_back(current->val);
                    current = current->right;
                }
                else{
                    predecessor->left = NULL;
                    // In postorder, we have already visited the current node after its right subtree
                    // so we do not add it to the answer list here.
                    current = current->left;
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
    vector<int> result = sol.postorderTraversal(root);
    
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

