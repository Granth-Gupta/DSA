#include <bits/stdc++.h>
using namespace std; 

void print(set<string> &s){
    for(string value: s){
        cout << value << endl;
    }
}

int main(){
    // Ordered
    set<string> s;
    s.insert("abc"); // log(n)
    s.insert("fgd");
    s.insert("amh");
    auto it = s.find("abc");
    print(s);
}