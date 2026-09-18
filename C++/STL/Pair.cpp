#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int,string> p;
    // p = make_pair(2,"abc");
    p = {2,"abc"};
    cout << p.first << " " << p.second <<endl;
    pair<int,string> p1 = p;
    p1.first = 3;
    cout << p.first << " " << p.second <<endl;
    pair<int,string> &p2 = p;
    p2.first = 3;
    cout << p.first << " " << p.second <<endl;
    pair<int,int> parray[3];
    int a[] = {1,2,3};
    int b[] = {2,3,4};
    pair<int,int> p_array[3];
    parray[0] = {1,2};
    parray[1] = {2,3};
    parray[2] = {3,4};
    swap(parray[0], parray[2]);
    for(int i = 0; i<3; i++){
        cout << parray[i].first << " " << parray[i].second << endl;
    }

    pair<int,int> p3;
    cin >> p3.first;
    cin >> p3.second;
    cout << p3.first << " " << p3.second << endl;
}