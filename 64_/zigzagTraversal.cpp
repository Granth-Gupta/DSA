// ZigZag Tree Traversal - GFG
// TC: O(N) where N is the number of nodes in the tree
// SC: O(N) for the queue and the result vector

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:

    // Function to return a list containing the zigzag level order traversal of the tree.
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            
            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                
                // Determine the index to fill based on the current direction
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->data;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            leftToRight = !leftToRight;

            for(auto val : level){
                ans.push_back(val);
            }

            // ans.insert(ans.end(), level.begin(), level.end());
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
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.zigZagTraversal(root);

    cout << "ZigZag Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}



