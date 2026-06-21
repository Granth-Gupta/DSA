// Hashmap basics - unordered_map
// Insertion, deletion, and searching in a hashmap - TC: O(1) on average, O(n) in worst case

#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;

int main(){
    unordered_map<string, int> m;

    // Insertion
    // 1
    pair<string, int> pair1 = make_pair("Meera", 1);
    m.insert(pair1);

    // 2
    pair<string, int> pair2("Anuj", 3);
    m.insert(pair2);

    // 3
    m["Meera"] = 1;
    
    // Updation not insertion
    m["Meera"] = 2;

    // Search
    cout << m["Meera"] << endl; // 2
    cout << m.at("Anuj") << endl; // 3

    cout << m["Anika"] << endl; // 0 -> Since no such key
    cout << m.at("Anika") << endl; // 0 -> Since entry already created in previous line 

    // cout << m.at("Granth") << endl; // Error -> As no entry insearted with key "Granth"
    cout << m["Granth"] << endl; // 0 -> Since no such key

    m.erase("Adya"); // No Error

    // iterator
    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    } 
    cout << endl;

    // OR
    for(auto i: m){
        cout << i.first << " " << i.second << endl;
    }

    cout << "\nNo order preserved. If we use map instead of unordered_map then order is preserved.";

    return 0;
}