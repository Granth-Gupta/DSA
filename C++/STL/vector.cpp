#include<bits/stdc++.h>
using namespace std;

// ''' 
// void printVector(vector<int> v){
// in this v is copy of vector
// since copy has O(n) complexity and use more space
// Therefore below is preferable
// '''

void printVector(vector<int> &v){
    cout << " Size = " << v.size() <<endl;
    for(int i = 0; i< v.size(); ++i){
        cout << v[i] << " ";
    }
    // v.size() - O(1)
    cout << endl <<endl;
}

int main(){
    double a[10];
    string s;
    
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0; i<n ;++i){
        v.push_back(i); //O(1)
    }
    printVector(v);

    // initial size can be assigned to vector
    vector<int> v1(5);
    v1.push_back(7);
    printVector(v1);

    // initial values can also be assigned
    vector<int> v2(5,3);
    v2.push_back(7);
    printVector(v2);
    v2.pop_back(); // O(1)
    printVector(v2);

    //  vector copy 
    vector<int> v3 = v; // O(n)

    // if array a = b then its not copy but both a and b have common address
    vector<int> &v4 = v; // common address



}