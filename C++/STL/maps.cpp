#include<bits/stdc++.h>
using namespace std;

void print(map<int,string> &m){
    for(auto &pr : m){
        cout << pr.first << " " << pr.second <<endl; // pr.first -> O(logn)
    }
    // This Loop -> O(nlogn) 
}

int main(){
    // map is sorted by key
    // unordered map is not sorted
    // Build on basis of comperision -> not by hashing

    map<int,string> m;
    m[3] = "abc"; // O(logn)
    m[1] = "pqr";
    m.insert({4,"xyz"}); 
    print(m);

    // If map<string,string> m, then O(s.size()*log(n))
    // s -> string key
    // Red Black Tree -> insertion, deletion in log(n) time. Ex- m[1] = "abc"
    // So, complexity in map depend upon key 

    auto it = m.find(5); // return an iterator -> O(logn)
    if(it != m.end()){
        m.erase(it); // log(n) , 3 must be present else segmentation fault
    }
    m.erase(3); // can give both key and iterator value but it must be present
    // m.clear();
    
    if(it == m.end()){ 
        cout << "No value";
    }
    else{
        cout << it->second << endl;
    }
}