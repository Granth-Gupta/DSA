// Merge 2 BST - CN {TC: O(N + M) SC: O(h1 + h2) - using Linked List}

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

// 1. Convert BST to sorted Linked List
// 2. Merge 2 sorted Linked List
// 3. Convert sorted Linked List to BST

void BSTToSortedLL(TreeNode *root, TreeNode* &head){
    if(root == NULL) 
        return;
    
    BSTToSortedLL(root->right, head);
    root->right = head;
    if(head != NULL)
        head->left = root;
    head = root;
    BSTToSortedLL(root->left, head);
}

TreeNode* merge(TreeNode *head1, TreeNode *head2){
    TreeNode *dummy = new TreeNode(-1);
    TreeNode *tail = dummy;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            tail->right = head1;
            head1->left = tail;
            head1 = head1->right;
        } else {
            tail->right = head2;
            head2->left = tail;
            head2 = head2->right;
        }
        tail = tail->right;
    }

    if(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
    }

    if(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
    }

    return dummy->right;
}

TreeNode* sortedLLToBST(TreeNode *&head, int n){
    if(n <= 0)
        return NULL;
    
    TreeNode *left = sortedLLToBST(head, n/2);
    TreeNode *root = head;
    root->left = left;
    head = head->right;
    root->right = sortedLLToBST(head, n - n/2 - 1);

    return root;
}

void inorder(TreeNode *root, vector<int> &v){
    if(root == NULL) 
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
};

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    TreeNode *head1 = NULL;
    TreeNode *head2 = NULL;

    BSTToSortedLL(root1, head1);
    BSTToSortedLL(root2, head2);

    TreeNode *mergedHead = merge(head1, head2);

    int n = 0;
    TreeNode *temp = mergedHead;
    while(temp != NULL){
        n++;
        temp = temp->right;
    }

    TreeNode *mergedRoot = sortedLLToBST(mergedHead, n);

    vector<int> v;

    inorder(mergedRoot, v);
    return v;
}   

int main(){
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    vector<int> merged = mergeBST(root1, root2);
    for(int i : merged){
        cout << i << " ";
    }

    return 0;
}   