// Reaarange String - CN - Approach 1 - Using HashMap and Priority Queue {TC: O(n log n), SC: O(n)}

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// Function to rearrange character of a string
// so that no two adjacent characters are same
string rearrangeString(string &s) {
    int n = s.length();

    // Store frequencies of all characters in string
    unordered_map<char, int> freq;
    for (int i = 0; i < n; i++)
        freq[s[i]]++;

    // Insert all characters with their frequencies
    // into a priority_queue
    priority_queue<pair<int, char>> pq;
    for (char c = 'a'; c <= 'z'; c++) {
        if (freq[c] > 0) {
            pq.push({ freq[c], c });
        }
    }

    string res = "";

    // work as the previous visited element
    // initial previous element be '#' and it's frequency '-1' 
    pair<int, char> prev = { -1, '#' };

    while (!pq.empty()) {
        
        // pop top element from queue and add it
        // to string.
        pair<int, char> p = pq.top();
        pq.pop();
        
        res.push_back(p.second);

        // IF frequency of previous character is less
        // than zero that means it is useless, we
        // need not to push it
        if (prev.first > 0)
            pq.push(prev);

        // Make current character as the previous 'char'
        // decrease frequency by 'one'
        p.first--;
        prev = p;
    }

    // If length of the resultant string and original
    // string is not same then string is not valid
    if (res.size() != n)
        return "NO SOLUTION";
    
    // Valid String
    return res;
}

int main() {
    string s = "aaabc";
    cout << rearrangeString(s);
    return 0;
}