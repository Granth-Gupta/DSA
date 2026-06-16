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
    cout << root->data << " ";
    
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

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(4);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(6);

    root->left->left = new BinaryTreeNode(1);
    root->left->right = new BinaryTreeNode(3);

    root->right->left = new BinaryTreeNode(5);
    root->right->right = new BinaryTreeNode(7);

    root = convertBST(root);

    return 0;
}