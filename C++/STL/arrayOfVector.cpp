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
    vector<int> v[N]; 
    // it's array of N vectors v[0],v[1],...
    // cout << v[0][1] -> like 2D vector where no. of rows are fixed but not no. of columns

    for(int i = 0; i<N; ++i){
        int n;
        cin >> n;
        for(int j=0; j<n; ++j){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for(int i=0; i<N; ++i){
        printVector(v[i]);
    }
}