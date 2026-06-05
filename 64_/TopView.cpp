// Top View of Binary Tree - GFG
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
    vector<int> topView(Node *root) {
        vector<int> ans;
        map<int, int> topNode;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int HD = temp.second;
            
            if(topNode.find(HD) == topNode.end()){
                topNode[HD] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, HD-1));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right, HD+1));
            }
        }
        
        for(auto i: topNode){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    
    Solution sol;
    vector<int> result = sol.topView(root);
    
    cout << "Top view of the binary tree is: ";
    for(int val : result){
        cout << val << " ";
    }
    
    return 0;
}