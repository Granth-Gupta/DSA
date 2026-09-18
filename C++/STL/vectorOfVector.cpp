#include <bits/stdc++.h>
using namespace std; 

void printVector(vector<int> &v){
    cout << " Size = " << v.size() <<endl;
    for(int i = 0; i< v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> v; 

    for(int i = 0; i<N; ++i){
        int n;
        cin >> n;
        v.push_back(vector<int> ()); // push_back empty vector
        for(int j=0; j<n; ++j){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
        v.push_back(v[i]);
    }

    for(int i=0; i<N; ++i){
        printVector(v[i]);
    }
}