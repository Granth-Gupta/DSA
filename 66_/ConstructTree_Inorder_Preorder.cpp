// Construct Tree from Inorder & Preorder - GFG
// TC: O(N) + O(NlogN) + O(N) ~ O(NlogN)
// SC: O(N) + O(N) ~ O(N)

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    void createMapping(vector<int> &inorder, map<int,int> &nodeToIndex, int n){
        for(int i = 0; i < n; i++){
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    Node* solve(vector<int> &inorder, vector<int> &preorder, int &index, int inorderStart, 
    int inorderEnd, int n, map<int,int> &nodeToIndex)
    {
        if(index >= n || inorderStart > inorderEnd)
            return NULL;
        
        int element = preorder[index++];
        Node* root = new Node(element);
        int position = nodeToIndex[element];
        
        root->left = solve(inorder, preorder, index, inorderStart, position-1, n, nodeToIndex);
        root->right = solve(inorder, preorder, index, position+1, inorderEnd, n, nodeToIndex);
        
        return root;
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preOrderIndex = 0;
        int n = inorder.size();
        map<int,int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
        
        Node* ans = solve(inorder, preorder, preOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};

void printPostOrder(Node* &node) {
    if (node == nullptr) return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->data << " ";
};

int main() {
    vector<int> inorder = {1, 6, 8, 7};
    vector<int> preorder = {1, 6, 7, 8};

    Solution solution;
    Node* root = solution.buildTree(inorder, preorder);

    cout << "PostOrder of constructed tree: ";
    printPostOrder(root);
    cout << endl;

    return 0;
}