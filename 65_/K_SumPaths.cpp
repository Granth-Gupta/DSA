// K Sum Paths - GFG (Approach #1 - using vector to store path)
// TC: O(N^2) where N is the number of nodes in the tree (in worst case, we might have to copy the path vector for each leaf node)
// SC: O(H) where H is the height of the tree (due to recursion stack) + O(H) for the path vector

// Constraints:
// 1 ≤ number of nodes ≤ 10^4
// -100 ≤ node value ≤ 100           
// -10^9 ≤ k ≤ 10^9                  --> Sum must be long long data type.

#include <iostream>
#include <vector>
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

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, int k, int &count, vector<int> &path){
        // Since O(N^2) is border line for 10^4 nodes, we use vector as path by reference to avoid copying the path vector for each leaf node.
        // Otherwise TLE error will occur.

        if(root == NULL){
            return;
        }
        
        path.push_back(root->data);
        
        solve(root->left,k,count,path);
        solve(root->right,k,count,path);
        
        int size = path.size();
        long long sum = 0;
        for(int i = size -1; i >= 0; i--){
            sum += path[i];
            if(sum == k){
                count++;
            }
        }
        path.pop_back();
    }
  
    int countAllPaths(Node *root, int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(6);

    int k = 6;

    Solution sol;
    int count = sol.countAllPaths(root, k);
    cout << "Number of paths with sum " << k << ": " << count << endl;

    return 0;
}