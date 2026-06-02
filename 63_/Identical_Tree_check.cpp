// Determine if two binary trees are identical. (GFG)
// Two binary trees are considered identical if they are structurally identical and the nodes have the same value.

// TC: O(n) where n is the number of nodes in the tree. We need to traverse both trees completely to check if they are identical.
// SC: O(h) where h is the height of the tree. In the worst case, the height of the tree can be equal to the number of nodes (in case of a skewed tree), so the space complexity can be O(n) in the worst case. However, in a balanced tree, the height would be log(n), resulting in a space complexity of O(log(n)).

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

bool isIdentical(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    }

    if(root1 == NULL || root2 == NULL) {
        return false;
    }

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);

    bool value = root1->data == root2->data;

    return left && right && value;
}

int main() {
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if(isIdentical(root1, root2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    return 0;
}
