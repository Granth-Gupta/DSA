#include<bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        for(int i=0 ; i<(nums.size()-1); i++){
            if(nums[i] == nums[i+1]){
                v.push_back(nums[i]);
            }
        }
        return v;
    }

int main(){
    vector<int> n = {1,2,1,4,2,5};
    vector<int> v = findDuplicates(n);
    for(auto a: v){
        cout << a << endl;
    }
}

