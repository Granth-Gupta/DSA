#include<bits/stdc++.h>
using namespace std;

// bool should_i_swap(pair<int,int> a,pair<int,int> b){
//     if(a.first != b.first){
//         if(a.first > b.first) return true;
//         return false;
//     }else{
//         if(a.second < b.second) return true;
//         return false; 
//     }
// }

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end(),cmp);
    sort(a.begin(),a.end(),greater<pair<int,int>>());
    // cmp -> if false then comperision occur 
    for(int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }
    cout << endl;
}