#include<bits/stdc++.h>
using namespace std;

void print(unordered_map<int,string> &m){
    for(auto &pr : m){
        cout << pr.first << " " << pr.second <<endl; // pr.first -> O(logn)
    }
}

int main(){
    // unordered map is not sorted
    // 1. Inbuilt inplementaion -> use hash table
    // 2. Time complexity -> insertion -> O(1) instead of O(logn)
    // 3. valid keys datatype -> key should be normal datatype
    // like unordered_map<pair<int,int>, string> m -> give compilation error
    // as hash value of pair<int,int> is not defined

    unordered_map<int,string> m;
    m[3] = "abc"; // O(1)
    m[1] = "pqr";
    m.insert({4,"xyz"});  // O(1)
    print(m);

    auto it = m.find(5); // O(1)
    if(it != m.end()){
        m.erase(it); // O(1)
    }
    m.erase(3); 
    // multimap -> in this we can enter duplicate keys

    // Should use unordered_map instead of map due to less time complexity
}