// Diameter of a Binary Tree (edge wise not node wise) - GFG

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

int height(Node* root, int &maxi) {
    if(root == NULL) {
            return 0;
        }

    int left = height(root->left, maxi);
    int right = height(root->right, maxi);

    // Diameter in edges
    maxi = max(maxi, left + right);

    return max(left, right) + 1;
}

int diameter(Node* root) {
    int maxi = 0;
    height(root, maxi);
    return maxi;
} 

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Diameter of Binary Tree: " << diameter(root) << endl;

    return 0;
}