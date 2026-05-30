#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> subset(vector<int> nums)
{
    vector<vector<int>> ans;
    int size = nums.size();

    for(int i=0; i<(1<<size); i++){
        vector<int> output;
        for(int j=0; j<size; j++){
            if (i & (1 << j)){
                output.push_back(nums[j]);
            }
        }
        ans.push_back(output);
    }

    return ans;
}

int main(){
    vector<int> input = {1,2,3};
    vector<vector<int>> subsets = subset(input);
    int n = subsets.size();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<subsets[i].size(); j++){
            cout << subsets[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}