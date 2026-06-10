// Find Kth largest element in a BST - CN

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    int solve(BinaryTreeNode<int>* root, int k, int &i){
        if(root == nullptr)
            return -1;
    
        int right = solve(root->right, k, i);

        if(right != -1)
            return right;
    
        i++;
        if(i == k)
            return root->data;

        return solve(root->left, k ,i);
    }

public:
    int kthLargest(BinaryTreeNode<int>* root, int k) {
        int i = 0;
        int ans = solve(root, k ,i);

        return ans;
    }
};

int main(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(5);
    root->left = new BinaryTreeNode<int>(3);
    root->right = new BinaryTreeNode<int>(6);
    root->left->left = new BinaryTreeNode<int>(2);
    root->left->right = new BinaryTreeNode<int>(4);

    Solution s;
    int k = 2;
    cout << s.kthLargest(root, k) << endl;
    
    return 0;
}

