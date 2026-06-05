#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, int> m;
    m[0] = 1;

    if(m.find(0) == m.end()){
        cout << "Not found" << endl;
    } else {
        cout << "Found" << endl;
    }

    return 0;
}