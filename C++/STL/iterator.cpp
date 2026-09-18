#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5};
    vector<int> ::iterator it = v.begin();
    // v.begin() -> first element position
    // v.end() -> next to last element position

    for(it = v.begin(); it < v.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;

    // it++ not it+1 -> must in case of maps and sets as they are not continously assigned in memory
    // it+1 moves to next address
    // it++ moves to next iterator irrespective of address

    vector<pair<int,int>> v1 = {{1,2},{3,5},{4,1}};
    // vector<pair<int,int>> ::iterator it1;
    //  auto automatically define with appropiate data type

    for(auto it1 = v1.begin(); it1 < v1.end(); it1++){
        cout << (*it1).first << " " << (it1->second) <<endl ; 
        // (*it).first or (it->first) are same
    }
    cout << endl;

    // iterator code in short

    // Range based loop
    // for(pair<int,int> &value : v1){
    for(auto &value : v1){
        cout << value.first << " "<< value.second <<endl;
    }
}