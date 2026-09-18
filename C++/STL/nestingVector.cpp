#include <bits/stdc++.h>
using namespace std; 

void printVector(vector<pair<int,int>> &v){
    cout << " Size = " << v.size() <<endl;
    for(int i = 0; i< v.size(); ++i){
        cout << v[i].first << " " << v[i].second <<endl;
    }
    cout << endl;
}

int main(){
    vector<pair<int,int>> v;
    // v = {{1,2},{3,4}};
    int n;
    cin >> n; 

    for(int i = 0; i< n; ++i){
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    printVector(v);

    // Array of vectors
    vector<int> v[10]; 
    // it's array of 10 vectors v[0],v[1],...
    // cout << v[0][1] -> like 2D vector where no. of rows are fixed but not no. of columns

    // vector of vector
    vector<vector<int>> v2;
}