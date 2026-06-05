// Left View of Binary Tree - GFG (Approach 1 - Using Level Order Traversal)
// TC: O(N) where N is the number of nodes in the tree
// SC: O(N) for the queue and result vector

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
    vector<int> leftView(Node *root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            ans.push_back(q.front()->data);
            
            for(int i=0; i<size; i++){
                Node* temp = q.front();
                q.pop();
                
                if(temp->left){
                    q.push(temp->left);
                }
                
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        
        return ans;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
    Solution sol;
    vector<int> leftViewNodes = sol.leftView(root);
    
    cout << "Left View of the Binary Tree: ";
    for(int val : leftViewNodes){
        cout << val << " ";
    }
    
    return 0;
}