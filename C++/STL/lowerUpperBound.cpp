#include<bits/stdc++.h>
using namespace std;

int main(){
    //  Lower bound -> same number pointer(if array) or iterator(if vector) if present 
    // otherwise pointer or iterator at which number is greater

    // Upper bound -> always pointer or iterator with greater number
    
    // O(logn) -> vector or array
    
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    auto ptr = lower_bound(a, a+n, 4);
    cout << (*ptr) << endl;
}