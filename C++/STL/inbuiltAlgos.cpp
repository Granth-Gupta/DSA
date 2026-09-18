#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin >> n;
     vector<int> v(n);
     for(int i=0; i<n; i++){
        cin >> v[i];
     }
     int min = *min_element(v.begin(),v.end()); // O(n)
     cout << min << endl;
     int max = *max_element(v.begin(),v.end()); // O(n)
     cout << max << endl;
     int sum = accumulate(v.begin(),v.end(),0);  // O(n)
     cout << sum << endl;
     int ct = count(v.begin()+1,v.end(),2); // O(n)
     cout << ct << endl;
     auto it = find(v.begin(),v.end(),4);  // O(n)
     if(it != v.end()){
        cout << *it << endl;
     }else{
        cout << "Element not found\n";
     }

     reverse(v.begin(),v.end());  // O(n)
     for(auto val : v){
        cout << val << " ";
     }
     cout << endl;
     string s = "anghtj";
     reverse(s.begin(),s.end());
     cout << s << endl;
}