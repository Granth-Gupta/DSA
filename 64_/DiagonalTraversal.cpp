// Diagonal Traversal of Binary Tree - GFG - Approach #1 (Recursion)
// TC: O(N) where N is the number of nodes in the tree
// SC: O(H) where H is the height of the tree (due to recursion stack) + O(N) for the result vector

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
private:
    void solve(Node* root, vector<vector<int>>& diag, int d) {
        if (root == NULL)
            return;

        if (d == diag.size()) {
            diag.push_back(vector<int>());
        }

        diag[d].push_back(root->data);

        // Left child goes to next diagonal
        solve(root->left, diag, d + 1);

        // Right child stays on same diagonal
        solve(root->right, diag, d);
    }

public:
    vector<int> diagonal(Node* root) {
        vector<vector<int>> diag;
        solve(root, diag, 0);

        vector<int> ans;

        for (auto& v : diag) {
            for (int x : v) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    Solution sol;
    vector<int> diagonal = sol.diagonal(root);

    cout << "Diagonal Traversal: ";
    for (int val : diagonal) {
        cout << val << " ";
    }

    return 0;
}