// Vertical Tree Traversal - GFG
// TC: O(N) where N is the number of nodes in the tree
// SC: O(N) for the map, queue, and result vector

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
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> ans;
        
        // [HD][level] -> nodes list 
        map<int, map<int, vector<int>>> nodes;
        
        // For Level order traversal with pair Node* and pair {HD,level}
        queue<pair<Node*, pair<int,int>>> q;
        
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()){
            pair<Node*, pair<int,int>> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int HD = temp.second.first;
            int level = temp.second.second;
            
            nodes[HD][level].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(HD-1, level+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, make_pair(HD+1, level+1)));
            }
        }

        // For ans like - [[4], [2], [1, 5, 6, 11], [3, 8, 9], [7], [10]]
        
        for(auto i : nodes){
            vector<int> col;
            for(auto j : i.second){
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
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
    vector<vector<int>> result = sol.verticalOrder(root);

    cout << "Vertical Order Traversal: " << endl;
    for (const auto& vec : result) {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}   