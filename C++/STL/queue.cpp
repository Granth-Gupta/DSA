#include<bits/stdc++.h>
using namespace std;

int main(){
    // Depth first search
    // push(),pop(),front()

    queue<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    while (!s.empty())
    {
        cout << s.front() << endl;
        s.pop();
    }
    
}