// Merge 2 BST - CN {TC: O(N + M) SC: O(N+M)}

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(TreeNode *root, vector<int> &v){
    if(root == NULL) 
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void merge(vector<int> &v1, vector<int> &v2, vector<int> &v){
    int i = 0, j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            v.push_back(v1[i]);
            i++;
        } else {
            v.push_back(v2[j]);
            j++;
        }
    }

    while(i < v1.size()){
        v.push_back(v1[i]);
        i++;
    }

    while(j < v2.size()){
        v.push_back(v2[j]);
        j++;
    }
}


vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> v1;
    vector<int> v2;

    inorder(root1, v1);
    inorder(root2, v2);

    vector<int> v;
    merge(v1, v2, v);

    return v;
}

int main(){
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    
    vector<int> ans = mergeBST(root1, root2);
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}