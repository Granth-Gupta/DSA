// Maximum Frequency Number - CN - Approach - unorderd_map / Hashmap

#include <bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n){
    unordered_map<int, int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for(int i = 0; i < n; i++){
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for(int i=0; i<n; i++){
        if(maxFreq == count[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
}

int main(){
    vector<int> arr = {2, 1, 3, 4, 3, 2, 1};

    int ans = maximumFrequency(arr, 7);
    cout << "Maximum Frequency Number is " << ans;

    return 0;
}