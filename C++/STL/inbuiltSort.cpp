#include<bits/stdc++.h>
using namespace std;

int main(){
    // Introsort -> best sorting algo
    // quick sort + heap sort + insertion sort
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    // array name is itselt poiter to 0th index
    sort(a,a+n);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}