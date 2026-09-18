#include <bits/stdc++.h>
using namespace std; 

int main(){
    // Any data structure that can be compaired 
    // can be used as a key for map
    // like pair,vector,set

    map<pair<int,int> ,int> m;
    pair<int,int> p1,p2;
    p1 = {1,2};
    p2 = {2,3};
    cout << (p1 < p2); // 1
    // First keys are compare
    // if they are same then values are compaired

    set<int> s1,s2;
    s1 = {1,2,3};
    s2 = {2,3};
    cout << (s1<s2) <<endl; // 1
}