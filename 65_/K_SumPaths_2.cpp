// K sum Paths - GFG (Approach #2 - using prefix sum (Hash Map) and unordered_map) --> TC - O(N)
// TC: O(N) where N is the number of nodes in the tree (each node is visited once)
// SC: O(H) where H is the height of the tree (due to recursion stack) + O(N) for the hash map in worst case (when all nodes are on the same path)

#include <iostream>
#include <unordered_map>
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
    void solve(Node* root, int k, int &count, long long sum, unordered_map<long long, int> &prefixSumCount){
        if(root == NULL){
            return;
        }
        
        sum += root->data;
        
        // Check if there is a prefix sum that equals current sum - k
        if(prefixSumCount.find(sum - k) != prefixSumCount.end()){
            count += prefixSumCount[sum - k];
        }
        
        // Add current sum to the hash map
        prefixSumCount[sum]++;
        
        solve(root->left, k, count, sum, prefixSumCount);
        solve(root->right, k, count, sum, prefixSumCount);
        
        // Backtrack: remove current sum from the hash map
        prefixSumCount[sum]--;
    }
  public:
    int countAllPaths(Node *root,int k)
    {
        int count = 0;
        long long sum = 0;
        unordered_map<long long, int> prefixSumCount;
        
        // Base case: there is one way to have a prefix sum of 0 (by taking no nodes)
        prefixSumCount[0] = 1;
        
        solve(root, k, count, sum, prefixSumCount);
        
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