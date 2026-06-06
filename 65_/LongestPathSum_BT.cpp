// Sum of nodes on the longest path - GFG
// TC: O(N) where N is the number of nodes in the tree
// SC: O(H) where H is the height of the tree (due to recursion stack)

#include <iostream>
#include <algorithm>
#include <climits>
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
    void solve(Node* root, int len, int &maxLen, int sum, int &maxSum){
        if(root == NULL){
            if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen){
                maxSum = max(sum, maxSum);
            }
            return;
        }
        
        sum = sum + root->data;
        
        solve(root->left, len+1, maxLen, sum, maxSum);
        solve(root->right, len+1, maxLen, sum, maxSum);
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        int len = 0;
        int maxLen = 0;
        
        int sum = 0;
        int maxSum = INT_MIN;
        
        solve(root, len, maxLen, sum, maxSum);
        
        return maxSum;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    // sumMax = max(7, 8, 10) = 10
    // {Len of longest path is 3}
    // 3 paths with len = 3 ,where sum is 7, 8 and 10 respectively
    // So, Find max sum among these 3 paths, which is 10

    // root->right->left->left = new Node(3); 
    // sumMax = 1++3+6+3 = 13
    // {Len of this path is 4 and sum is 13}
    
    Solution sol;
    cout << sol.sumOfLongRootToLeafPath(root) << endl; // Output: 10 (1 + 2 + 4)
    
    return 0;
}