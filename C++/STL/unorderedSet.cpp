#include <bits/stdc++.h>
using namespace std; 

void print(unordered_set<string> &s){
    for(string value: s){
        cout << value << endl;
    }
}

int main(){
    // Ordered
    // valid keys datatype -> key should be normal datatype
    unordered_set<string> s;
    s.insert("abc"); // O(1)
    s.insert("fgd");
    s.insert("amh");
    auto it = s.find("abc");
    print(s);
}