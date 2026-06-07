// Construct Tree from Inorder & Postorder - GFG
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
    
    Node* solve(vector<int> &inorder, vector<int> &postorder, int &index, int inorderStart, 
    int inorderEnd, int n, map<int,int> &nodeToIndex)
    {
        if(index < 0 || inorderStart > inorderEnd)
            return NULL;
        
        int element = postorder[index--];
        Node* root = new Node(element);
        int position = nodeToIndex[element];
        
        root->right = solve(inorder, postorder, index, position+1, inorderEnd, n, nodeToIndex);
        root->left = solve(inorder, postorder, index, inorderStart, position-1, n, nodeToIndex);
        
        return root;
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        int postOrderIndex = n-1;
        map<int,int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
        
        Node* ans = solve(inorder, postorder, postOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};

void printPreOrder(Node* &node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
};

int main() {
    vector<int> inorder = {1, 6, 8, 7};
    vector<int> postorder = {1, 8, 7, 6};

    Solution sol;
    Node* root = sol.buildTree(inorder, postorder);

    cout << "Preorder of the constructed tree: ";
    printPreOrder(root);
    cout << endl;

    return 0;
}