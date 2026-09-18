#include<bits/stdc++.h>
using namespace std;

int main(){
    // O(n) -> sets and maps
    // In maps -> upper and lower bound only on keys
    
    set<int> s;
    for(int i = 0; i<(int)(1e6); i++){
        s.insert(rand());
    }
    for(int i=0; i<(int)1e5; i++){
        // auto it = lower_bound(s.begin(), s.end(), rand()); -> error 
        auto it = s.lower_bound(rand()); // in case of sets and maps
    }
}