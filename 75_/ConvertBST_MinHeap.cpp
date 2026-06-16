// Convert BST to Min Heap (Given: BST is in CBT, In Min Heap , left < right )

#include <bits/stdc++.h> 
using namespace std;

class BinaryTreeNode {
		
public :
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(int data) {
	this -> left = NULL;
	this -> right = NULL;
	this -> data = data;
	}
};

void inorder(BinaryTreeNode* root, vector<int> &in){
    if(root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void preorder(BinaryTreeNode* root, vector<int> &in, int &index){
    if(root == NULL)
        return;

    root->data = in[index++];
    
    preorder(root->left, in, index);
    preorder(root->right, in, index);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    vector<int> in;
    inorder(root, in);

    int index = 0;
    preorder(root, in, index);

    return root;
}
