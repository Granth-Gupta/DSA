#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    int a = 0;
    int y = x;
    if(x > 0){
        while(y != 0){
            a = (a)*10 + (y%10);
            y = y/10;
        }
        if(a==x){
            return true;
        }
        else return false;
    }
    else return false;
}

int main(){
    int x;
    cin >> x;
    cout << isPalindrome(x);
    cout << (-231);
}