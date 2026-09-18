#include<bits/stdc++.h>
using namespace std;

 bool isValid(string s) {
        bool a;
        map<char,int> m = {{'(',1},{')',-1},{'{',0},{'}',0},{'[',2},{']',-2}};
        stack<int> st;
        st.push(m[s[0]]);
        
        for(int i=1; i<s.size(); i++){
            if((st.top() + m[s[i]]) != 0){
                st.push(m[s[i]]);
            }
            else{
                st.pop();
            }
        }
        if(st.size() == 0){
            a = true;
        }else{
            a = false;
        }
        return a;
}

int main(){
    // Balanced paranthesis
    // Next greater element
    // push(),pop(),top()

    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << isValid("({)");
    
}