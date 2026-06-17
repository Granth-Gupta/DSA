// Merge K sorted arrays into one sorted array - Approach 3: Using Min Heap with compare operator and Node class {TC: O(n log(k))} {SC: O(k)}

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        int row;
        int col;

        Node(int d, int r, int c){
            this->data = d;
            this->row = r;
            this->col = c;
        }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    
        priority_queue<Node*, vector<Node*>, compare> minHeap;
    
        for(int i=0; i<k; i++){
            Node* temp = new Node(kArrays[i][0], i, 0);
            minHeap.push(temp);
        }
    
        vector<int> result;
    
        while(!minHeap.empty()){
            Node* temp = minHeap.top();
            minHeap.pop();
    
            result.push_back(temp->data);
    
            int row = temp->row;
            int col = temp->col;
    
            if(col + 1 < kArrays[row].size()){
                Node* next = new Node(kArrays[row][col + 1], row, col + 1);
                minHeap.push(next);
            }
        }
    
        return result;
}

int main(){
    vector<vector<int>> kArrays = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    vector<int> mergedArray = mergeKSortedArrays(kArrays, 3);

    for (int num : mergedArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}