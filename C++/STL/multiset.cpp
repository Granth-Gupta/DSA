#include <bits/stdc++.h>
using namespace std; 

void print(multiset<string> &s){
    for(string value: s){
        cout << value << endl;
    }
}

int main(){
    // repeation allowed
    // Use red black tree
    multiset<string> s;
    s.insert("abc"); // log(n)
    s.insert("fgd");
    s.insert("amh");
    s.insert("fgd");
    auto it = s.find("fgd"); // iterator of 1st "abc"
    s.erase(it); // only one "abc" erase
    // s.erase("fgd"); -> all "fgd" erase
    print(s);
}