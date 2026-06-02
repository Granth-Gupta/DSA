// Check for Balanced Tree. (GFG)
// A balanced tree is a tree in which the difference between the heights of left and right subtrees is not more than one for any node of the tree.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

pair<bool, int> balancedfast(Node* root) {
    if(root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = balancedfast(root->left);
    pair<bool, int> right = balancedfast(root->right);

    bool leftans = left.first;
    bool rightans = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.first = leftans && rightans && diff;
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

bool isBalanced(Node* root) {
    return balancedfast(root).first;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    if(isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}