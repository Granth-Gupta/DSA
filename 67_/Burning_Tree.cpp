// Burning Tree - GFG 
// TC: O(N) where N is the number of nodes in the tree
// SC: O(N) for the queue and map data structures used in the algorithm

// C++ program to find the minimum time required to burn the complete binary tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    Node* createMapping(Node* root, int target, map<Node*, Node*>& nodeToParent) {
        
        Node* res = NULL;

        queue<Node*> q;
        q.push(root);

        nodeToParent[root] = NULL;

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            if (front->data == target)
                res = front;

            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }

            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }

        return res;
    }

    int burningTree(Node* targetNode,
                    map<Node*, Node*>& nodeToParent) {

        map<Node*, bool> visited;
        queue<Node*> q;

        q.push(targetNode);
        visited[targetNode] = true;

        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    flag = true;
                    visited[front->left] = true;
                    q.push(front->left);
                }

                if (front->right && !visited[front->right]) {
                    flag = true;
                    visited[front->right] = true;
                    q.push(front->right);
                }

                if (nodeToParent[front] &&
                    !visited[nodeToParent[front]]) {
                    flag = true;
                    visited[nodeToParent[front]] = true;
                    q.push(nodeToParent[front]);
                }
            }

            if (flag)
                ans++;
        }

        return ans;
    }

public:
    int minTime(Node* root, int target) {
        map<Node*, Node*> nodeToParent;

        Node* targetNode =
            createMapping(root, target, nodeToParent);

        return burningTree(targetNode, nodeToParent);
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 5;
    Solution sol;
    cout << "Minimum time to burn the tree: " << sol.minTime(root, target) << endl;

    return 0;
}