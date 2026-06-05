// Bottom View of Binary Tree - GFG
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
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        map<int, int> bottomNode;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int HD = temp.second;
            
            bottomNode[HD] = frontNode->data;
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, HD-1));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right, HD+1));
            }
        }
        
        for(auto i: bottomNode){
            ans.push_back(i.second);
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    Solution sol;
    vector<int> result = sol.bottomView(root);
    
    cout << "Bottom View: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}