// Vertical Tree Traversal - GFG

#include <iostream>
#include <vector>
#include <map>
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
        // Function to return a list containing the vertical order traversal of the tree.
        vector<int> verticalOrder(Node *root) {
            vector<int> ans;
            if(root == NULL) return ans;
            
            map<int, vector<int>> m; // Map to store nodes based on their horizontal distance
            queue<pair<Node*, int>> q; // Queue to perform level order traversal
            q.push({root, 0}); // Start with the root node at horizontal distance 0
            
            while(!q.empty()){
                auto front = q.front();
                q.pop();
                Node* node = front.first;
                int hd = front.second; // Horizontal distance
                
                m[hd].push_back(node->data); // Add the node's data to the corresponding horizontal distance
                
                if(node->left) q.push({node->left, hd - 1}); // Left child has horizontal distance -1
                if(node->right) q.push({node->right, hd + 1}); // Right child has horizontal distance +1
            }
            
            // Traverse the map and add nodes to the answer vector in vertical order
            for(auto it : m){
                for(int val : it.second){
                    ans.push_back(val);
                }
            }
            
            return ans;
        }  
};

int main() {
    // Example usage:
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    Solution sol;
    vector<int> result = sol.verticalOrder(root);
    
    cout << "Vertical Order Traversal: ";
    for(int val : result){
        cout << val << " ";
    }
    
    return 0;
}   